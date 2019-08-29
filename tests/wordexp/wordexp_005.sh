IFS='.'
PATH=$PATH:./tests/exec/

show_args $(echo -n `echo AB.CD`)

show_args $(echo -n "`echo AB.CD`")

show_args "$(echo -n `echo AB.CD`)"

show_args $(echo -n `echo AB.CD`)

./tests/exec/show_args $(echo -n 12.`echo AB.CD`)

./tests/exec/show_args $(echo -n 12."`echo AB.CD`")
