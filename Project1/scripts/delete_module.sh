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

main() {
	local argv=(${@})
	check_args ${argv[@]}

	local src_dir=${argv[0]}
	check_if_dir_not_exists ${src_dir}

	local module_name=${argv[1]}

	rm -rf ${src_dir}/${module_name}
}

main ${@}