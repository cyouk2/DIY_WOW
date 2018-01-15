/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#include "AI/ScriptDevAI/PreCompiledHeader.h"
#include "Spells/Spell.h"
#include <cstring>
//enum
//{
//    SPELL_DOMINION_SOUL1     = 10202,
//    NPC_EMBERSTRIFE1         = 10321
//};

bool GossipHello_ItemUse_Item_teleport(Player *player, Item* _Item, SpellCastTargets const& targets)
{
    player->ADD_GOSSIP_ITEM( 3, " 世界主城传送 " , 1, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 3, " 初级副本传送 " , 1, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 3, " 中级副本传送 " , 1, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 3, " 团队副本传送 " , 1, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 3, " 野外BOSS传送 " , 1, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 3, " 世界风景传送1 " , 1, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 3, " 世界风景传送2 " , 1, GOSSIP_ACTION_INFO_DEF + 7);
    player->SEND_GOSSIP_MENU(99990,_Item->GetObjectGuid());
    
    player->SendEquipError(EQUIP_ERR_NONE, _Item, NULL);

    //if (const SpellEntry* pSpellInfo = GetSpellStore()->LookupEntry<SpellEntry>(SPELL_DOMINION_SOUL1))
    //    Spell::SendCastResult(player, pSpellInfo, SPELL_FAILED_TARGET_AURASTATE);

    return true;
}

void SendDefaultMenu_ItemUse_Item_teleport(Player *player, Item *_Item, uint32 action, SpellCastTargets const& targets)
{
    switch(action) {
        // 主城
        case GOSSIP_ACTION_INFO_DEF + 1 :
            
            player->ADD_GOSSIP_ITEM( 0, " [联盟] 暴风城 " , 2, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [联盟] 铁炉堡 " , 2, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [联盟] 达纳苏斯 " , 2, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [部落] 奥格瑞玛 " , 2, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [部落] 雷霆崖 " , 2, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [部落] 幽暗城 " , 2, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " [中立] 棘齿城 " , 2, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " [中立] 藏宝海湾 " , 2, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99987,_Item->GetObjectGuid());
            break;
        // 初级副本
        case GOSSIP_ACTION_INFO_DEF + 2 :
            
            player->ADD_GOSSIP_ITEM( 0, " [14] 怒焰裂谷 " , 4, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [19] 死亡矿井 " , 4, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [22] 哀嚎洞穴 " , 4, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [24] 影牙城堡 " , 4, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [26] 黑暗深渊 " , 4, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [27] 暴风城监狱 " , 4, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " [31] 剃刀沼泽 " , 4, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " [33] 诺莫瑞根 " , 4, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, " [40] 血色修道院 " , 4, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, " [42] 剃刀高地 " , 4, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, " [45] 奥达曼 " , 4, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99986,_Item->GetObjectGuid());
            break;

        // 中级副本
        case GOSSIP_ACTION_INFO_DEF + 3 :
            
            player->ADD_GOSSIP_ITEM( 0, " [46] 祖尔法拉克 " , 5, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [49] 玛拉顿 " , 5, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [53] 失落的神庙 " , 5, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [57] 黑石深渊 " , 5, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [60] 通灵学院 " , 5, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [60] 厄运之槌 (北区) " , 5, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " [60] 厄运之槌 (东区) " , 5, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " [60] 厄运之槌 (西区) " , 5, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, " [60] 斯坦索姆 " , 5, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, " [60] 黑石塔下 " , 5, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99993,_Item->GetObjectGuid());
            break;

        // 高级副本
        case GOSSIP_ACTION_INFO_DEF + 4 :
                
            player->ADD_GOSSIP_ITEM( 0, " [团] 溶火之心 " , 6, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [团] 黑石塔上 " , 6, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [团] 祖尔格拉布 " , 6, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [团] 黑翼之巢 " , 6, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [团] 安其拉 " , 6, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [团] 安其拉废墟 " , 6, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " [团] 奥妮克希亚的巢穴 " , 6, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " [团] 纳克萨玛斯 " , 6, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, " [团] 冰龙巢穴 " , 6, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99); 
            player->SEND_GOSSIP_MENU(99994,_Item->GetObjectGuid());
            break;

       // 野外BOSS传送
        case GOSSIP_ACTION_INFO_DEF + 5 :
            
            player->ADD_GOSSIP_ITEM( 0, " [野外]暮色森林 " , 9, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " [野外]辛特兰 " , 9, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " [野外]灰谷 " , 9, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " [野外]艾萨拉 " , 9, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " [野外]菲拉斯 " , 9, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " [野外]诅咒之地 " , 9, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99988,_Item->GetObjectGuid()); 
            break;
        // 風景傳送
        case GOSSIP_ACTION_INFO_DEF + 6 :
            player->ADD_GOSSIP_ITEM( 0, " 海加尔山 " , 11, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " 翡翠圣地 " , 11, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " 时光之穴 " , 11, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " 黑暗之门 " , 11, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " 双塔山 " , 11, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " 梦境之树 " , 11, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " GM之岛" , 11, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, " 海加尔山-暴雪路障 " , 11, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99989,_Item->GetObjectGuid()); 
            break;
        case GOSSIP_ACTION_INFO_DEF + 7 :
            player->ADD_GOSSIP_ITEM( 0, " 天涯海滩 " , 12, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, " 安戈洛环形山 " , 12, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, " 比吉尔的飞艇残骸 " , 12, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, " 石堡瀑布" , 12, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, " 地铁海底" , 12, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, " 工程之岛" , 12, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, " KaLaZan" , 12, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 7, " 上一级菜单 " , 15, GOSSIP_ACTION_INFO_DEF + 99);
            player->SEND_GOSSIP_MENU(99997,_Item->GetObjectGuid());
        break;
    }
}

bool GossipSelect_ItemUse_Item_teleport(Player *player, Item *_Item, uint32 sender, uint32 action, SpellCastTargets const& targets)
{
    switch(sender) {
        // 主选单
        case 1 :
            SendDefaultMenu_ItemUse_Item_teleport(player, _Item, action,targets);
            break;
        // 各大主城
        case 2 :
            switch(action) {
                // 暴风城
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(0,-9065,434,94,0);
                    break;
                // 铁炉堡
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(0,-5032,-819,495,0);
                    break;
                // 达纳苏斯
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(1,9961,2055,1329,0);
                    break;
                // 奥格瑞玛
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(1,1317,-4383,27,0);
                    break;
                // 雷霆崖
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(1,-1391,140,23,0);
                    break;
                // 幽暗城
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(0,1909,235,53,0);
                    break;
                // 棘齿城 */
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(1,-977,-3788,6,0);
                    break;
                // 藏宝海湾
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(0,-14302,518,9,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 4:
            switch(action) {
                // [14] 怒焰裂谷 统一格式说明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(389,2.024650,-10.021000,-16.187500,0);
                    break;
                // [19] 死亡矿井
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(36,-16.4,-383.07,61.78,0);
                    break;
                // [22] 哀嚎洞穴
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(43,-161.841995,133.266998,-73.866203,0);
                    break;
                // [24] 影牙城堡
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(33,-228.19,2110.56,76.89,0);
                    break;
                // [26] 黑暗深渊
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(48,-150.367004,102.995003,-40.555801,0);
                    break;
                // [27] 暴风城监狱
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(34,48.29,0.45,-16.14,0);
                    break;
                // [31] 剃刀沼泽
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(47,1943,1544,82,0);
                    break;
                // [33] 诺莫瑞根
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(90,-332.562988,-3.445,-152.845993,0);
                    break;
                // [40] 血色修道院
                case GOSSIP_ACTION_INFO_DEF + 9 :
                    player->TeleportTo(189,855.903992,1321.939941,18.673000,0);
                    break;
                // [42] 剃刀高地
                case GOSSIP_ACTION_INFO_DEF + 10 :
                    player->TeleportTo(129,2593.209961,1109.459961,51.093300,0);
                    break;
                // [45] 奥达曼
                case GOSSIP_ACTION_INFO_DEF + 11 :
                    player->TeleportTo(70,-227.529007,45.009800,-46.019600,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        // 中级副本
        case 5:
            switch(action) {
                // [46] 祖尔法拉克 统一格式说明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(209,1213,841,8.9,0);
                    break;
                // [49] 玛拉顿
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(349,1012.700012,-459.317993,-43.547100,0);
                    break;
                // [53] 失落的神庙
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(109,-313.369995,99.955399,-131.848999,0);
                    break;
                // [57] 黑石深渊
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(230,456.928986,34.927700,-69.388100,0);
                    break;
                // [60] 通灵学院
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(289,199,126,135,0);
                    break;
                // [60] 厄运之槌 (北区)
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(429,255.164001,-17.024200,-2.560600,0);
                    break;
                // [60] 厄运之槌 (东区)
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(429,46.24,-155.53,-2.71349,0);
                    break;
                // [60] 厄运之槌 (西区)
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(429,32.722599,159.417007,-3.470170,0);
                    break;
                // [60] 斯坦索姆
                case GOSSIP_ACTION_INFO_DEF + 9 :
                    player->TeleportTo(329,3392,-3379,143,0);
                    break;
                // [60] 黑石塔下
                case GOSSIP_ACTION_INFO_DEF + 10 :
                    player->TeleportTo(229,78.19,-227.63,49.72,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;

        // 高级副本
        case 6:
            switch(action) {
                // [团] 溶火之心 统一格式说明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(409,1089.601685,-470.190247,-106.413055,0);
                    break;
                // [团] 黑石塔上
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(229,78.339836,-227.793518,49.7103,0);
                    break;
                // [团] 祖尔格拉布
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(309,-11916,-1251.469971,92.32,0);
                    break;
                // [团] 黑翼之巢
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(469,-7674.470215,-1108.380005,396.649994,0);
                    break;
                // [团] 安其拉
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(531,-8212.002930,2034.474854,129.141342,0);
                    break;
                // [团] 安其拉废墟
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(509,-8443.475586,1518.648560,31.906958,0);
                    break;
                // [团] 奥妮克希亚的巢穴
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(249,30.010290,-58.840508,-5.325367,0);
                    break;
                //[团] 纳克萨玛斯 
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(533,3005.87,-3435.01,293.882,0);
                    break;
                // [团] 冰龙巢穴
                case GOSSIP_ACTION_INFO_DEF + 9 :
                    player->TeleportTo(533,3700.35,-5185.92,143.957,4.403038,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        // 野外BOSS坐标
        case 9:
            switch(action) {
                // 暮色森林 统一格式说明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(0,-10526.168945,-434.996796,50.894821,0);
                    break;
                // 辛特兰
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(0,759.605713,-3893.341309,116.475304,0);
                    break;
                // 灰谷
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(1,3120.289307,-3439.444336,139.566345,1);
                    break;
                //  艾萨拉
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(1,2622.219971,-5977.930176,100.562897,1);
                    break;
                // 菲拉斯
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(1,-2741.290039,2009.481323,31.877323,1);
                    break;
                // 诅咒之地
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(0,-12234.000000,-2474.000000,-3.000000,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 11 :
            switch(action) {
                //海加爾山 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(1,4603.946777,-3879.250977,944.183472,1);
                    break;
                //翡翠聖地 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(1,3968.264648,-1290.036011,240.326889,5.927989);
                    break;
                //時光之穴 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(1,-8173.930176,-4737.463867,33.777351,4.772119);
                    break;
                //黑暗之門 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(0,-11849.031250,-3201.170654,-28.885090,3.280838);
                    break;
                //雙塔山 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(1,-3331.353271,2225.728271,30.987701,6.267522);
                    break;
                //夢境之樹 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(1,-2914.756104,1902.199341,34.741035,5.690404);
                    break;
                //GM之島 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(1, 16222.1 ,16252.1,12.5872,1);
                    break;
                //暴雪建設公司路障 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 8 :
                    player->TeleportTo(1,5478.060059,-3730.850098,1593.439941,5.610376);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 12 :
            switch(action) {
                //天涯海灘 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 1 :
                    player->TeleportTo(1,-9851.617188,-3608.474121,8.939731,2.513388);
                    break;
                //安戈洛環形山 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 2 :
                    player->TeleportTo(1,-8562.096680,-2106.056641,8.852538,0.090425);
                    break;
                //比吉爾的飛艇殘骸 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 3 :
                    player->TeleportTo(1,-4014.003418,-3768.186523,42.123295,5.220697);
                    break;
                //石堡瀑布 統一格式?明：(MapID, X, Y, Z, 0);
                case GOSSIP_ACTION_INFO_DEF + 4 :
                    player->TeleportTo(0,-9481.493164,-3326.915283,8.864347,0.846896);
                    break;
                //地鐵海底
                case GOSSIP_ACTION_INFO_DEF + 5 :
                    player->TeleportTo(369, -9.96166,1238.17,-126.102,0);
                    break;
                //工程師之島
                case GOSSIP_ACTION_INFO_DEF + 6 :
                    player->TeleportTo(451, 16299.464844, 16272.843750, 69.443901 ,0);
                    break;
                // KaLaZan
                case GOSSIP_ACTION_INFO_DEF + 7 :
                    player->TeleportTo(0, 11037.7 ,1999.49, 92.9823 ,0);
                    break;
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 15:
            GossipHello_ItemUse_Item_teleport(player,_Item,targets);
            break;
    }
    return true;
}

void AddSC_Item_teleport()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="Item_teleport";
    newscript->pItemUse = &GossipHello_ItemUse_Item_teleport;
    newscript->pGossipSelect_Item = &GossipSelect_ItemUse_Item_teleport;
    newscript->RegisterSelf();
}

 
