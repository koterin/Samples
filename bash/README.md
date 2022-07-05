## edit.sh
How to read input from user and filter it

## log_analyzer.sh

How to analyze the log file: row count, unique file count and changes count.
Run like that:

```
log_analyzer.sh files.log
```

## quest1.sh

Actually log something via bash.
Description:
1. Getting the full path (here I used the one and only hardcoded file)
ls "`pwd`/history_of_vim.txt" >> files.log

2. Counting SHA256 hash -
shasum -a 256 history_of_vim.txt >> files.log

3. Adding date and time
date '+%F %X' >> files.log

4. File size - yes, it's not precise, but it's human-readable, which is nicer
du -sh history_of_vim.txt >> files.log

5. Adding '-'
printf ' - ' >> files.log

6. Adding algorythm name
printf 'sha256' >> files.log

7. Deleting extra file names (left from other commands)
sed 's/history_of_vim.txt//' files.log

5. Deleting the last line
sed -i "" '/^[[:space:]]*$/d' files.log

6. Counting unique rows
awk '{print $1}' files.log | sort | uniq -c | awk '{print $1}'

7. Counting unique hashes
awk '{print $8}' files.log | sort | uniq -c | awk '{print $1}' | wc -l | tr -d ' '

8. Showing the output in one line
awk '{print $8}' files.log | sort | uniq -c | awk '{print $1}' | wc -l | tr -d ' ' | tr -d '\n' && awk '{print $8}' files.log | sort | uniq -c | awk '{print $1}' | wc -l | tr -d ' '
