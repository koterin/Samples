
#counting all rows
sed -n '$=' $1 | tr -d '\n'
echo " " | tr -d '\n'

#counting unique filenames
awk '{print $1}' $1 | sort | uniq -c | awk '{print $1}' | wc -l | tr -d ' ' | tr -d '\n'
echo " " | tr -d '\n'

#counting unique hash lines
awk '{print $8}' $1 | sort | uniq -c | awk '{print $1}' | wc -l | tr -d ' '
