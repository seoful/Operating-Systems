echo "s" > week01/file.txt
link week01/file.txt week10/_ex2.txt
inode=$(ls -i week01/file.txt)
inode=${inode%% *}
echo $(find week10 -inum $inode) > week10/ex2.txt
echo $(find week10 -inum $inode -exec rm {} \;) >> ex2.txt