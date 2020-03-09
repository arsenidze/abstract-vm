set -o nounset

check_args() {
	local length=${#}

	if [ ${length} -ne 2 ]; then 
		echo "usage: $0 <dir> <module_name>"
  		exit 0
	fi
}

check_if_dir_not_exists() {
	local d=${1}

	if [ ! -d ${d} ]; then
		echo "error: directory - '${d}' doesn't exists"
		exit
	fi
}

create_module_interface() {
	local module_name=${1}
	local file_name=${module_name}.h
	local upper_name=$(echo "$module_name" | tr '[:lower:]' '[:upper:]')

	touch ${file_name}
	echo \
"#ifndef ${upper_name}_H
# define ${upper_name}_H

class ${module_name}
{
public:
	${module_name}();
	${module_name}(const ${module_name}& src);
	~${module_name}();
	${module_name}& operator=(const ${module_name}& rhs);
private:
};

#endif" > ${file_name}
}

create_module_implementation() {
	local module_name=${1}
	local file_name=${module_name}.cpp

	local double_quote='"'

	touch ${file_name}
	echo \
"#include ${double_quote}${module_name}.h${double_quote}

${module_name}::${module_name}()
{
}

${module_name}::${module_name}(const ${module_name}& src)
{
	*this = src;
}

${module_name}::~${module_name}()
{
}

${module_name}& ${module_name}::operator=(const ${module_name}& rhs)
{
	if (this == &rhs)
  		return (*this);
 	// ADD CODE
 	return (*this);
}" > ${file_name}
}

main() {
	local argv=(${@})
	check_args ${argv[@]}

	local src_dir=${argv[0]}
	check_if_dir_not_exists ${src_dir}

	local module_name=${argv[1]}

	mkdir -p ${src_dir}/${module_name}
	cd ${src_dir}/${module_name}
	create_module_interface ${module_name}
	create_module_implementation ${module_name}
	cd ..
}

main ${@}