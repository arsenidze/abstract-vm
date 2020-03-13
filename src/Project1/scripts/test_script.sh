set -o nounset

check_args() {
	local length=${#}

	if [ ${length} -ne 1 ]; then 
		echo "usage: $0 <module_name>"
  		exit 0
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
	local upper_name=$(echo "$module_name" | tr '[:lower:]' '[:upper:]')

	touch ${file_name}
	echo \
"${module_name}::${module_name}()
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
	local argv=${@}
	check_args ${argv}
	local module_name=${argv[0]}

	mkdir ${module_name}
	cd ${module_name}
	create_module_interface ${module_name}
	create_module_implementation ${module_name}
	cd ..
}

main ${@}