echo $1 "was logged"

printf '\n' >> files.log

#ls "`pwd`/$1" | { tr -d '\n'; } >> files.log
echo "src/$1" | { tr -d '\n'; }  >> files.log

printf ' - ' | { tr -d '\n'; } >> files.log
stat -f%z $1 | { tr -d '\n'; } >> files.log
printf ' - ' | { tr -d '\n'; } >> files.log
date '+%F %H':'%M' | { tr -d '\n'; } >> files.log
printf ' - ' | { tr -d '\n'; } >> files.log
shasum -a 256 $1 | { tr -d " $1"; } | { tr -d "\n"; } >> files.log
printf ' - ' | { tr -d '\n' ;} >> files.log
printf 'sha256' | { tr -d '\n'; } >> files.log

#just in case there are empty lines - delete them
sed -i "" '/^[[:space:]]*$/d' files.log
