touch $1
pushd `dirname $0` > /dev/null
SCRIPTPATH=`pwd -P`
popd > /dev/null
cp "$SCRIPTPATH/template.cpp" $1