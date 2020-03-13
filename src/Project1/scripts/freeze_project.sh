archive_tool=zip

archive_tool . prev_version

rm -rf src
rm -rf imports

mkdir project_versions
mv prev_version project_versions
