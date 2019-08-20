cd not_found  | cat -e
cd not_found  2>& 1 | cat -e
cd not_found  2>& - | cat -e
