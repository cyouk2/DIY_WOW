#!/bin/bash

ADDITIONAL_PATH="/root/wow_db_chinese/"
DB_HOST="localhost"
DB_PORT="3306"
DATABASE="mangos"
USERNAME="mangos"
PASSWORD="mangos"

MYSQL_COMMAND="mysql -h$DB_HOST -P$DB_PORT -u$USERNAME $DATABASE"
## Updates
echo "> Processing database updates ..."
COUNT=0
for UPDATE in "${ADDITIONAL_PATH}"*.sql
do
  if [ -e "$UPDATE" ]
  then
    echo "    Appending $UPDATE"
    #$MYSQL_COMMAND < "$UPDATE"
    #if [[ $? != 0 ]]
    #then
    #  echo "ERROR: cannot apply $UPDATE"
    #  exit 1
    #fi
    ((COUNT++))
  fi
done
if [ "$COUNT" != 0 ]
then
  echo "  $COUNT DB updates applied successfully"
else
  echo "  Did not found any new DB update to apply"
fi
