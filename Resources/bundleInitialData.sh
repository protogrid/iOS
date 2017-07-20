#!/bin/bash
set -e

function contains() {
    local n=$#
    local value=${!n}
    for ((i=1;i < $#;i++)) {
        if [ "${!i}" == "${value}" ]; then
            echo "y"
            return 0
        fi
    }
    echo "n"
    return 1
}

genericErrorMessage="Something seems to have gone wrong with the initial replication process. Please delete the files in ${applicationPath} and run Protogrid again.
If this doesn't work, please contact protogrid@ategra.ch."

currentDir=$(pwd)

#find all initiation completed files
initiationCompletedFilePaths=(`find ~/Library/Developer/CoreSimulator -name PGridInitiationCompleted`)

#nothing found? nothing more to do here.
if [ "${#initiationCompletedFilePaths[@]}" -eq 0 ]; then
	echo "no initiation completed files found. nothing to do for seed data."
	exit 0
fi

#extract application path for first initiation completed file (the others are to be discarded)
firstInitiationCompletedFilePath=${initiationCompletedFilePaths[0]}
applicationPath="${firstInitiationCompletedFilePath/\/Documents\/PGridInitiationCompleted/}"
if [ -z "$applicationPath" ]; then
	echo "Unexpected Error: could not extract application path after finding an initiation completed file."
	exit 2
fi

#find all couchbase lite files
cblFilesDir="${applicationPath}/Library/Application Support/CouchbaseLite"
cblFilePaths=(`find "${cblFilesDir}" -name *.cblite*`)
if [ "${#cblFilePaths[@]}" -eq 0 ]; then
	echo "Error: no CouchbaseLite files found in designated path, even though initiation completed has been signaled.
${genericErrorMessage}"
	exit 3
fi

#check if users_mirror, roles, system and main exists
#Note: Passing multiple arrays fo functions is annoyingly complicated in Bash, so I just repeat the code here.
usersFilename="users_mirror.cblite2"
if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${usersFilename}) == "n" ]; then
	echo "Error: no ${usersFilename} found in designated path, even though initiation completed has been signaled.
${genericErrorMessage}"
	exit 3
fi
# usersFilenameShm="users_mirror.cblite-shm"
# if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${usersFilenameShm}) == "n" ]; then
# 	echo "Error: no ${usersFilenameShm} found in designated path, even though initiation completed has been signaled.
# ${genericErrorMessage}"
# 	exit 3
# fi
# usersFilenameWal="users_mirror.cblite-wal"
# if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${usersFilenameWal}) == "n" ]; then
# 	echo "Error: no ${usersFilenameWal} found in designated path, even though initiation completed has been signaled.
# ${genericErrorMessage}"
# 	exit 3
# fi

rolesFilename="roles.cblite2"
if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${rolesFilename}) == "n" ]; then
	echo "Error: no ${rolesFilename} found in designated path, even though initiation completed has been signaled.
${genericErrorMessage}"
	exit 3
fi
# rolesFilenameShm="roles.cblite-shm"
# if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${rolesFilenameShm}) == "n" ]; then
# 	echo "Error: no ${rolesFilenameShm} found in designated path, even though initiation completed has been signaled.
# ${genericErrorMessage}"
# 	exit 3
# fi
# rolesFilenameWal="roles.cblite-wal"
# if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${rolesFilenameWal}) == "n" ]; then
# 	echo "Error: no ${rolesFilenameWal} found in designated path, even though initiation completed has been signaled.
# ${genericErrorMessage}"
# 	exit 3
# fi

systemFilename="system.cblite2"
if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${systemFilename}) == "n" ]; then
	echo "Error: no s${systemFilename} found in designated path, even though initiation completed has been signaled.
${genericErrorMessage}"
	exit 3
fi
# systemFilenameShm="system.cblite-shm"
# if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${systemFilenameShm}) == "n" ]; then
# 	echo "Error: no s${systemFilenameShm} found in designated path, even though initiation completed has been signaled.
# ${genericErrorMessage}"
# 	exit 3
# fi
# systemFilenameWal="system.cblite-wal"
# if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${systemFilenameWal}) == "n" ]; then
# 	echo "Error: no s${systemFilenameWal} found in designated path, even though initiation completed has been signaled.
# ${genericErrorMessage}"
# 	exit 3
# fi

mainFilename="main.cblite2"
if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${mainFilename}) == "n" ]; then
	echo "Error: no ${mainFilename} found in designated path, even though initiation completed has been signaled.
${genericErrorMessage}"
	exit 3
fi
# mainFilenameShm="main.cblite-shm"
# if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${mainFilenameShm}) == "n" ]; then
# 	echo "Error: no ${mainFilenameShm} found in designated path, even though initiation completed has been signaled.
# ${genericErrorMessage}"
# 	exit 3
# fi
# mainFilenameWal="main.cblite-wal"
# if [ $(contains "${cblFilePaths[@]}" ${cblFilesDir}/${mainFilenameWal}) == "n" ]; then
# 	echo "Error: no ${mainFilenameWal} found in designated path, even though initiation completed has been signaled.
# ${genericErrorMessage}"
# 	exit 3
# fi

#copy to the projects' seed directory
seedDir="${currentDir}/Seed"
mkdir -p "${seedDir}"
set +e
cp -r "${cblFilesDir}/${usersFilename}" "${seedDir}/"
ret=$?
if [ $ret -ne 0 ]; then
	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
	exit 4
fi
# cp "${cblFilesDir}/${usersFilenameShm}" "${seedDir}/"
# ret=$?
# if [ $ret -ne 0 ]; then
# 	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
# 	exit 4
# fi
# cp "${cblFilesDir}/${usersFilenameWal}" "${seedDir}/"
# ret=$?
# if [ $ret -ne 0 ]; then
# 	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
# 	exit 4
# fi

cp -r "${cblFilesDir}/${rolesFilename}" "${seedDir}/"
ret=$?
if [ $ret -ne 0 ]; then
	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
	exit 4
fi
# cp "${cblFilesDir}/${rolesFilenameShm}" "${seedDir}/"
# ret=$?
# if [ $ret -ne 0 ]; then
# 	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
# 	exit 4
# fi
# cp "${cblFilesDir}/${rolesFilenameWal}" "${seedDir}/"
# ret=$?
# if [ $ret -ne 0 ]; then
# 	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
# 	exit 4
# fi

cp -r "${cblFilesDir}/${systemFilename}" "${seedDir}/"
ret=$?
if [ $ret -ne 0 ]; then
	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
	exit 4
fi
# cp "${cblFilesDir}/${systemFilenameShm}" "${seedDir}/"
# ret=$?
# if [ $ret -ne 0 ]; then
# 	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
# 	exit 4
# fi
# cp "${cblFilesDir}/${systemFilenameWal}" "${seedDir}/"
# ret=$?
# if [ $ret -ne 0 ]; then
# 	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
# 	exit 4
# fi

cp -r "${cblFilesDir}/${mainFilename}" "${seedDir}/"
ret=$?
if [ $ret -ne 0 ]; then
	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
	exit 4
fi
# cp "${cblFilesDir}/${mainFilenameShm}" "${seedDir}/"
# ret=$?
# if [ $ret -ne 0 ]; then
# 	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
# 	exit 4
# fi
# cp "${cblFilesDir}/${mainFilenameWal}" "${seedDir}/"
# ret=$?
# if [ $ret -ne 0 ]; then
# 	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
# 	exit 4
# fi

#copy the initiation completed file to the seed directory. It contains the version that has been seeded.
cp "${firstInitiationCompletedFilePath}" "${seedDir}/PGridSeedVersion"
ret=$?
if [ $ret -ne 0 ]; then
	echo "Error: Could not copy to the seed directory ${seedDir}. Please check the permissions."
	exit 4
fi

set -e
#delete all initiation completed files $$$
for path in ${initiationCompletedFilePaths[@]}; do rm "$path" && echo "${path} deleted"; done

exit 0