SRC_FOLDER="src"
OBJ_FOLDER="obj"
EXEC_NAME="apple1"

# clear any previous object
rm -rf $OBJ_FOLDER
rm -f $EXEC_NAME

# build all source code
for FILE in $SRC_FOLDER/*.c
do
    cc -g -c $FILE
done

# move all objects to appropriate folder
mkdir -p $OBJ_FOLDER
mv *.o $OBJ_FOLDER

# create executable out of the objects
cc -g -o $EXEC_NAME $OBJ_FOLDER/*.o
