
echo -n 'Enter substring to be replaced'
read substr
if [[ "$substr" == *"/"* ]]; then
	echo "/-symbol is not allowed!"
	exit 1
fi

echo -n 'Enter string to write instead'
read newstr

if [[ "$newstr" == *"/"* ]]; then
	echo "/-symbol is not allowed!"
	exit 1
fi

echo -n 'Enter the path to the file'
read glpath

if ! [ -f "$glpath" ]; then 
    echo "The specified file does not exist."
    exit 1
fi

#substitution
sed "s/$substr/"$newstr"/g" $glpath

#in case of fire give eveyone every possible permission
chmod +x quest1.sh
./quest1.sh $glpath
