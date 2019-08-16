for file in "$2"*
do
	$1 $file
	printf "\\n\\n\\n"
done
