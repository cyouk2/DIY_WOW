print(">>Script: Teleport stone.")
--54844
--菜单所有者 --默认炉石
local itemEntry = 6948
--阵营
local TEAM_ALLIANCE=0
local TEAM_HORDE=1
--菜单号
local MMENU=1
local TPMENU=2
--菜单类型
local FUNC=1
local MENU=2
local TP=3


--GOSSIP_ICON 菜单图标
local GOSSIP_ICON_CHAT            = 0                    -- 对话
local GOSSIP_ICON_VENDOR          = 1                    -- 货物
local GOSSIP_ICON_TAXI            = 2                    -- 传送
local GOSSIP_ICON_TRAINER         = 3                    -- 训练（书）
local GOSSIP_ICON_INTERACT_1      = 4                    -- 复活
local GOSSIP_ICON_INTERACT_2      = 5                    -- 设为我的家
local GOSSIP_ICON_MONEY_BAG       = 6                    -- 钱袋
local GOSSIP_ICON_TALK            = 7                    -- 申请 说话+黑色点
local GOSSIP_ICON_TABARD          = 8                    -- 工会（战袍）
local GOSSIP_ICON_BATTLE          = 9                    -- 加入战场 双剑交叉
local GOSSIP_ICON_DOT             = 10                   -- 加入战场

local Instances={--副本表
        {249,0},{249,1},{269,1},{309,0},
        {409,0},{469,0},
        {509,0},{531,0},{532,0},{533,0},{533,1},
        {534,0},{540,1},{542,1},{543,1},{544,0},{545,1},{546,1},{547,1},{548,0},
        {550,0},{552,1},{553,1},{554,1},{555,1},{556,1},{557,1},{558,1},
        {560,1},{564,0},{565,0},{568,0},
        {574,1},{575,1},{576,1},{578,1},
        {580,0},{585,1},{595,1},{598,1},{599,1},
        {600,1},{601,1},{602,1},{603,0},{603,1},{604,1},{608,1},
        {615,0},{615,1},{616,0},{616,1},{619,1},{624,0},{624,1},
        {631,0},{631,1},{631,2},{631,3},{632,1},
        {649,0},{649,1},{649,2},{649,3},--十字军的试炼
        {650,1},{658,1},{668,1},
        {724,0},{724,1},{724,2},{724,3},
}

local Stone={
    GetTimeASString=function(player)
        local inGameTime=player:GetTotalPlayedTime()
        local days=math.modf(inGameTime/(24*3600))
        local hours=math.modf((inGameTime-(days*24*3600))/3600)
        local mins=math.modf((inGameTime-(days*24*3600+hours*3600))/60)
        return days.."天"..hours.."时"..mins.."分"
    end,
    GoHome=function(player)--回到家
        player:CastSpell(player,8690,true)    
        player:ResetSpellCooldown(8690, true)    
        player:SendBroadcastMessage("已经回到家")
    end,


    SetHome=function(player)--设置当前位置为家
        local x,y,z,mapId,areaId=player:GetX(),player:GetY(),player:GetZ(),player:GetMapId(),player:GetAreaId() 
        player:SetBindPoint(x,y,z,mapId,areaId)
        player:SendBroadcastMessage("已经设置当前位置为家")
    end,


    OpenBank=function(player)--打开银行
        player:SendShowBank(player)
        player:SendBroadcastMessage("已经打开银行")
    end,


    WeakOut=function(player)--移除复活虚弱
        if(player:HasAura(15007))then
            player:RemoveAura(15007)    --移除复活虚弱
            player:SetHealth(player:GetMaxHealth())
            --self:RemoveAllAuras()    --移除所有状态
            player:SendBroadcastMessage("你的身上的复活虚弱状态已经被移除。")
        else
            player:SendBroadcastMessage("你的身上没有复活虚弱状态。")
        end
    end,


    OutCombat=function(player)--脱离战斗
        if(player:IsInCombat())then
            player:ClearInCombat()
            player:SendAreaTriggerMessage("你已经脱离战斗")
            player:SendBroadcastMessage("你已经脱离战斗。")
        else
            player:SendAreaTriggerMessage("你并没有在战斗。")
            player:SendBroadcastMessage("你并没有在战斗。")
        end
    end,
	
	
    UnBind=function(player)    --副本解绑
        local nowmap=player:GetMapId()
        for k, v in pairs(Instances) do 
            local mapid=v[1]
            if(mapid~=nowmap)then
                player:UnbindInstance(v[1],v[2])
            else
                player:SendBroadcastMessage("你所在的当前副本无法解除绑定。")
            end
        end
        player:SendAreaTriggerMessage("已经解除所有副本的绑定")
        player:SendBroadcastMessage("已经解除所有副本的绑定。")
    end,    

}


local Menu={
    [MMENU]={--主菜单
        {FUNC, "传送回家",         Stone.GoHome,    GOSSIP_ICON_CHAT,        false,"是否传送回|cFFF0F000家|r ?"},
        {FUNC, "记录位置",         Stone.SetHome,    GOSSIP_ICON_INTERACT_1, false,"是否设置当前位置为|cFFF0F000家|r ?"},
        {FUNC, "在线银行",         Stone.OpenBank,    GOSSIP_ICON_MONEY_BAG},
        {MENU, "地图传送",         TPMENU,            GOSSIP_ICON_BATTLE},
        {MENU, "其他功能",        MMENU+0x10,        GOSSIP_ICON_INTERACT_1},
        {FUNC, "解除副本绑定",     Stone.UnBind,    GOSSIP_ICON_INTERACT_1, false,"是否解除所有副本绑定 ?"},
        {MENU, "职业技能训练师",MMENU+0x20,        GOSSIP_ICON_BATTLE},
        {MENU, "专业技能训练师",MMENU+0x30,        GOSSIP_ICON_BATTLE},
        {FUNC, "强制脱离战斗",     Stone.OutCombat,GOSSIP_ICON_CHAT},
    },
    [MMENU+0x10]={--其他功能
        {FUNC, "解除虚弱",         Stone.WeakOut,        GOSSIP_ICON_INTERACT_1, false,"是否解除虚弱，并回复生命 ?"},
    },
    [TPMENU]={--传送菜单
        {MENU, "主要城市",            TPMENU+0x10,GOSSIP_ICON_BATTLE},
        {MENU, "东部王国",            TPMENU+0x20,GOSSIP_ICON_BATTLE},
        {MENU, "卡利姆多",            TPMENU+0x30,GOSSIP_ICON_BATTLE},
        {MENU, "经典旧世界地下城",    TPMENU+0x40,GOSSIP_ICON_BATTLE},
        {MENU, "团队地下城",          TPMENU+0x50,GOSSIP_ICON_BATTLE},
        {MENU, "风景传送",            TPMENU+0x60,GOSSIP_ICON_BATTLE},
        {MENU, "其他传送",            TPMENU+0x70,GOSSIP_ICON_BATTLE},
        {MENU, "野外BOSS传送",        TPMENU+0x80,GOSSIP_ICON_BATTLE},
    },
    [TPMENU+0x10]={--主要城市
        {TP, "暴风城", 0, -8842.09, 626.358, 94.0867, 3.61363,TEAM_ALLIANCE},
        {TP, "达纳苏斯", 1, 9869.91, 2493.58, 1315.88, 2.78897,TEAM_ALLIANCE},
        {TP, "铁炉堡", 0, -4900.47, -962.585, 501.455, 5.40538,TEAM_ALLIANCE},
        {TP, "奥格瑞玛", 1, 1601.08, -4378.69, 9.9846, 2.14362,TEAM_HORDE},
        {TP, "雷霆崖",  1, -1274.45, 71.8601, 128.159, 2.80623,TEAM_HORDE},
        {TP, "幽暗城", 0, 1633.75, 240.167, -43.1034, 6.26128,TEAM_HORDE},
        {TP, "[中立]藏宝海湾",0, -14281.9, 552.564, 8.90422, 0.860144},
        {TP, "[中立]棘齿城",    1,    -955.21875,-3678.92,8.29946,    0},
        {TP, "[中立]加基森",    1,    -7122.79834,-3704.82,14.0526,    0},
    },
    [TPMENU+0x20]={--东部王国
        {TP, "艾尔文森林", 0,  -9449.06, 64.8392, 56.3581, 3.0704},
        {TP, "丹莫罗", 0,  -5603.76, -482.704, 396.98, 5.2349},
        {TP, "提瑞斯法林地", 0,  2274.95, 323.918, 34.1137, 4.2436},
        {TP, "洛克莫丹", 0,  -5405.85, -2894.15, 341.972, 5.4823},
        {TP, "银松森林", 0,  505.126, 1504.63, 124.808, 1.7798},
        {TP, "西部荒野", 0,  -10684.9, 1033.63, 32.5389, 6.0738},
        {TP, "赤脊山", 0,  -9447.8, -2270.85, 71.8224, 0.28385},
        {TP, "暮色森林", 0,  -10531.7, -1281.91, 38.8647, 1.5695},
        {TP, "希尔斯布莱德丘陵", 0,  -385.805, -787.954, 54.6655, 1.0392},
        {TP, "湿地", 0,  -3517.75, -913.401, 8.86625, 2.6070},
        {TP, "奥特兰克山脉",0,  275.049, -652.044, 130.296, 0.50203},
        {MENU, "下一页", TPMENU+0x120,GOSSIP_ICON_CHAT},
    },
    [TPMENU+0x120]={--东部王国    2
        {TP, "阿拉希高地", 0,  -1581.45, -2704.06, 35.4168, 0.490373}, 
        {TP, "荆棘谷",  0,  -11921.7, -59.544, 39.7262, 3.7357},
        {TP, "荒芜之地", 0,  -6782.56, -3128.14, 240.48, 5.6591},
        {TP, "悲伤沼泽", 0,  -10368.6, -2731.3, 21.6537, 5.2923},
        {TP, "辛特兰", 0,  112.406, -3929.74, 136.358, 0.981903}, 
        {TP, "灼热峡谷",  0,  -6686.33, -1198.55, 240.027, 0.91688},
        {TP, "诅咒之地", 0,  -11184.7, -3019.31, 7.29238, 3.20542}, 
        {TP, "燃烧平原",  0,  -7979.78, -2105.72, 127.919, 5.10148},
        {TP, "西瘟疫之地", 0,    1743.69, -1723.86, 59.6648, 5.23722}, 
        {TP, "东瘟疫之地", 0,  2280.64, -5275.05, 82.0166, 4.747},
    },
    [TPMENU+0x30]={--卡利姆多
        {TP, "达希尔", 1, 9889.03, 915.869, 1307.43, 1.9336},
        {TP, "杜隆塔尔", 1, 228.978, -4741.87, 10.1027, 0.416883},
        {TP, "莫高雷", 1, -2473.87, -501.225, -9.42465, 0.6525},
        {TP, "黑海岸", 1, 6463.25, 683.986, 8.92792, 4.33534},
        {TP, "贫瘠之地", 1, -575.772, -2652.45, 95.6384, 0.006469},
        {TP, "石爪山脉", 1, 1574.89, 1031.57, 137.442, 3.8013},
        {TP, "灰谷森林", 1, 1919.77, -2169.68, 94.6729, 6.14177},
        {TP, "千针石林", 1, -5375.53, -2509.2, -40.432, 2.41885},
        {TP, "凄凉之地", 1, -656.056, 1510.12, 88.3746, 3.29553},
        {TP, "尘泥沼泽", 1, -3350.12, -3064.85, 33.0364, 5.12666},
        {TP, "菲拉斯", 1, -4808.31, 1040.51, 103.769, 2.90655},
        {TP, "塔纳利斯沙漠", 1, -6940.91, -3725.7, 48.9381, 3.11174},
        {TP, "艾萨拉", 1, 3117.12, -4387.97, 91.9059, 5.49897},
        {TP, "费伍德森林", 1, 3898.8, -1283.33, 220.519, 6.24307},
        {TP, "安戈洛环形山", 1, -6291.55, -1158.62, -258.138, 0.457099},
        {TP, "希利苏斯", 1, -6815.25, 730.015, 40.9483, 2.39066},
        {TP, "冬泉谷", 1, 6658.57, -4553.48, 718.019, 5.18088},
    },
    [TPMENU+0x40]={--经典旧世界地下城
        {TP, "诺莫瑞根",0, -5163.54, 925.423, 257.181, 1.57423},
        {TP, "死亡矿井", 0, -11209.6, 1666.54, 24.6974, 1.42053},
        {TP, "暴风城监狱", 0, -8799.15, 832.718, 97.6348, 6.04085,TEAM_ALLIANCE},
        {TP, "怒焰裂谷",  1, 1811.78, -4410.5, -18.4704, 5.20165,TEAM_HORDE},
        {TP, "剃刀高地",  1, -4657.3, -2519.35, 81.0529, 4.54808}, 
        {TP, "剃刀沼泽", 1, -4470.28, -1677.77, 81.3925, 1.16302}, 
        {TP, "血色修道院", 0, 2873.15, -764.523, 160.332, 5.10447},
        {TP, "影牙城堡", 0, -234.675, 1561.63, 76.8921, 1.24031},
        {TP, "哀嚎洞穴", 1, -731.607, -2218.39, 17.0281, 2.78486},
        {TP, "黑暗深渊", 1, 4249.99, 740.102, -25.671, 1.34062},
        {TP, "黑石深渊", 0, -7179.34, -921.212, 165.821, 5.09599}, 
        {TP, "黑石塔", 0, -7527.05, -1226.77, 285.732, 5.29626},
        {TP, "厄运之槌", 1, -3520.14, 1119.38, 161.025, 4.70454},
        {TP, "玛拉顿", 1, -1421.42, 2907.83, 137.415, 1.70718},
        {TP, "通灵学院", 0, 1269.64, -2556.21, 93.6088, 0.620623}, 
        {TP, "斯坦索姆", 0, 3352.92, -3379.03, 144.782, 6.25978}, 
        {TP, "沉没的神庙", 0, -10177.9, -3994.9, -111.239, 6.01885},
        {TP, "奥达曼",0, -6071.37, -2955.16, 209.782, 0.015708},
        {TP, "祖尔法拉克", 1, -6801.19, -2893.02, 9.00388, 0.158639},
    },
    [TPMENU+0x50]={--团队地下城
        {TP, "黑翼之巢", 229, 152.451, -474.881, 116.84, 0.001073},
        {TP, "熔火之心", 230, 1126.64, -459.94, -102.535, 3.46095}, 
        {TP, "纳克萨玛斯", 571, 3668.72, -1262.46, 243.622, 4.785}, 
        {TP, "奥妮克希亚的巢穴", 1, -4708.27, -3727.64, 54.5589, 3.72786}, 
        {TP, "安其拉废墟", 1, -8409.82, 1499.06, 27.7179, 2.51868},
		{TP, "祖尔格拉布", 0, -11916.7, -1215.72, 92.289, 4.72454},
        {TP, "安其拉神殿", 1, -8240.09, 1991.32, 129.072, 0.941603},
    },

    [TPMENU+0x60]={--风景传送
        {TP, "GM之岛",            1, 16222.1,        16252.1,    12.5872,    0},
        {TP, "时光之穴",        1,-8173.93018,    -4737.46387,33.77735,    0},
        {TP, "双塔山",            1,-3331.35327,    2225.72827,    30.9877,    0},
        {TP, "梦境之树",        1,-2914.7561,    1902.19934,    34.74103,    0},
        {TP, "恐怖之岛",        1, 4603.94678,    -3879.25097,944.18347,    0},
        {TP, "天涯海滩",        1,-9851.61719,    -3608.47412,8.93973,    0},
        {TP, "安戈洛环形山",    1,-8562.09668,    -2106.05664,8.85254,    0},
        {TP, "石堡瀑布",        0,-9481.49316,    -3326.91528,8.86435,    0},
        {TP, "暴雪建设公司路障",1, 5478.06006,    -3730.8501,    1593.44,    0},
    },


    [TPMENU+0x70]={--其他传送 
        {TP, "古拉巴什竞技场", 0, -13181.8, 339.356, 42.9805, 1.18013},
        --Alliance
        {TP, "奥特兰战场",0,    5.599396,-308.73822,132.26651,        0,TEAM_ALLIANCE},
        {TP, "阿拉希战场",0,    -1229.860352,-2545.07959,21.180079,    0,TEAM_ALLIANCE},
        --Horde
        {TP, "阿拉希战场",0,    -847.953491,-3519.764893,72.607727,    0,TEAM_HORDE},
        {TP, "奥特兰战场",0,    396.471863,-1006.229126,111.719086,    0,TEAM_HORDE},
        {TP, "战歌峡谷",  1,    1036.794800,-2106.138672,122.94553,    0,TEAM_HORDE},
    },
    [TPMENU+0x80]={--野外BOSS传送
        {TP, "暮色森林",    0,-10526.16895,-434.996796,50.8948,    0},
        {TP, "辛特兰",    0,759.605713,-3893.341309,116.4753,    0},
        {TP, "灰谷",        1,3120.289307,-3439.444336,139.5663,0},
        {TP, "艾萨拉",    1,2622.219971,-5977.930176,100.5629,0},
        {TP, "菲拉斯",    1,-2741.290039,2009.481323,31.8773,    0},
        {TP, "诅咒之地",    0,-12234,-2474,-3,                    0},
    },
    [MMENU+0x20]={--联盟职业技能训练师
        --Alliance
        {TP, "战士训练师",     0,-8682.700195, 322.091125, 109.437958,    0,TEAM_ALLIANCE},
        {TP, "圣骑士训练师",     0,-8573.793945, 877.343018, 106.519310,    0,TEAM_ALLIANCE},
        {TP, "死亡骑士训练师",     0,2365.21, -5658.35, 426.06,        0,TEAM_ALLIANCE},
        {TP, "萨满训练师",     0,-9032.573242, 545.842590, 72.160950,    0,TEAM_ALLIANCE},
        {TP, "猎人训练师",     0,-8422.097656, 550.078674, 95.448730,    0,TEAM_ALLIANCE},
        {TP, "德鲁伊训练师",    1, 7870.23, -2586.97, 486.95,            0,TEAM_ALLIANCE},
        {TP, "盗贼训练师",     0,-8751.876953, 381.321930, 101.056236,    0,TEAM_ALLIANCE},
        {TP, "法师训练师",    0,-9009.386719, 875.746765, 29.621387,    0,TEAM_ALLIANCE},
        {TP, "术士训练师",     0,-8972.834961, 1027.723511, 101.40416,    0,TEAM_ALLIANCE},
        {TP, "牧师训练师",     0,-8517.649414, 858.083801, 109.81385,     0,TEAM_ALLIANCE},
        --Horde
        {TP, "战士训练师",    1, 1971.24, -4805.08, 56.99,    0,TEAM_HORDE},
        {TP, "圣骑士训练师",1, 1936.14, -4138.31, 41.03,0,TEAM_HORDE},
        {TP, "死亡骑士训练师",0, 2365.21, -5658.35, 426.06,    0,TEAM_HORDE},
        {TP, "萨满训练师",    1, 1928.482, -4228.17, 42.3219,    0,TEAM_HORDE},
        {TP, "猎人训练师",    1, 2135.33, -4610.78, 54.3865,    0,TEAM_HORDE},
        {TP, "德鲁伊训练师",    1, 7870.23, -2586.97, 486.95,0,TEAM_HORDE},
        {TP, "盗贼训练师",    1, 1776.47, -4285.65, 7.44,        0,TEAM_HORDE},
        {TP, "法师训练师",    1, 1468.58, -4221.86, 59.22,    0,TEAM_HORDE},
        {TP, "术士训练师",    1, 1838.19, -4355.78, -14.71,    0,TEAM_HORDE},
        {TP, "牧师训练师",    1, 1454.71, -4179.42, 61.56,     0,TEAM_HORDE},
    },
    [MMENU+0x30]={--专业技能训练师
        --Alliance
        {TP, "武器训练师",     0,-8793.120117, 613.002991, 96.856400,    0,TEAM_ALLIANCE},
        {TP, "骑术训练师",     0,-9443.556641, -1388.178345, 46.9881,    0,TEAM_ALLIANCE},
        --Horde
        {TP, "武器训练师",    1, 2093.829346, -4821.349609, 24.382,    0,TEAM_HORDE},
        {TP, "骑术训练师",    530, 9268.768555, -7508.026367, 38.09,    0,TEAM_HORDE},
    }, 
}


function Stone.AddGossip(player, item, id)
    player:GossipClearMenu()--清除菜单
    local Rows=Menu[id] or {}
    local Pteam=player:GetTeam()
    local teamStr,team="",player:GetTeam()
    if(team==TEAM_ALLIANCE)then
        teamStr    ="[|cFF0070d0联盟|r]"
    elseif(team==TEAM_HORDE)then 
        teamStr    ="[|cFFF000A0部落|r]"
    end
    for k, v in pairs(Rows) do 
        local mtype,text,icon,intid=v[1],( v[2] or "???" ), (v[4] or GOSSIP_ICON_CHAT), (id*0x100+k)
        if(mtype==MENU)then
            player:GossipMenuAddItem(icon, text, 0, (v[3] or id )*0x100)
        elseif(mtype==FUNC)then
            local code,msg,money=v[5],(v[6]or ""), (v[7] or 0)
            if((code==true or code ==false))then
                player:GossipMenuAddItem(icon, text, money, intid, code, msg, money)
            else
                player:GossipMenuAddItem(icon, text, 0, intid)
            end
        elseif(mtype==TP)then
            local mteam=v[8] or TEAM_NONE
            if(mteam==Pteam)then
                player:GossipMenuAddItem(GOSSIP_ICON_TAXI, teamStr..text, 0, intid, false,"是否传送到 |cFFFFFF00"..text.."|r ?",0)
            elseif(mteam ==TEAM_NONE)then
                player:GossipMenuAddItem(GOSSIP_ICON_TAXI, text, 0, intid, false,"是否传送到 |cFFFFFF00"..text.."|r ?",0)
            end
        else
            player:GossipMenuAddItem(icon, text, 0, intid)
        end
    end
    if(id > 0)then--添加返回上一页菜单
        local length=string.len(string.format("%x",id))
        if(length>1)then
            local temp=bit_and(id,2^((length-1)*4)-1)
            if(temp ~= MMENU)then
                player:GossipMenuAddItem(GOSSIP_ICON_CHAT,"上一页", 0,temp*0x100)
            end
        end
    end
    if(id ~= MMENU)then--添加返回主菜单
        player:GossipMenuAddItem(GOSSIP_ICON_CHAT,"主菜单", 0, MMENU*0x100)
    else
        player:GossipMenuAddItem(GOSSIP_ICON_CHAT, "在线总时间：|cFF000080"..Stone.GetTimeASString(player).."|r", 0, MMENU*0x100)
    end


    player:GossipSendMenu(1, item)--发送菜单
end


function Stone.ShowGossip(event, player, item)
    player:MoveTo(0,player:GetX(),player:GetY(),player:GetZ()+0.01)--移动就停止当前施法
    Stone.AddGossip(player, item, MMENU)
end


function Stone.SelectGossip(event, player, item, sender, intid, code, menu_id)
    local menuid=math.modf(intid/0x100)    --菜单组
    local rowid    =intid-menuid*0x100        --第几项
    if(rowid== 0)then
        Stone.AddGossip(player, item, menuid)
    else
        player:GossipComplete()    --关闭菜单
        local v=Menu[menuid] and Menu[menuid][rowid]
        if(v)then                        --如果找到菜单项
            local mtype=v[1] or MENU
            if(mtype==MENU)then
                Stone.AddGossip(player, item, (v[3] or MMENU))
            elseif(mtype==FUNC)then                    --功能
                local f=v[3]
                if(f)then
                    player:ModifyMoney(-sender)        --扣费
                    f(player, code)
                end
            elseif(mtype==TP)then                    --传送
                local map,mapid,x,y,z,o=v[2],v[3],v[4], v[5], v[6],v[7] or 0
                local pname=player:GetName()--得到玩家名
                if(player:Teleport(mapid,x,y,z,o,TELE_TO_GM_MODE))then--传送
                    Nplayer=GetPlayerByName(pname)--根据玩家名得到玩家
                    if(Nplayer)then
                        Nplayer:SendBroadcastMessage("已经到达 "..map)
                        Nplayer:ModifyMoney(-sender)--扣费
                    end
                else
                    print(">>Eluna Error: Teleport Stone : Teleport To "..mapid)
                end
            end
        end
    end
end


RegisterItemGossipEvent(itemEntry, 1, Stone.ShowGossip)
RegisterItemGossipEvent(itemEntry, 2, Stone.SelectGossip)
