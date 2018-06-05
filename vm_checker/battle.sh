RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

let "playernu = 0"
for f in ./../vm_filler/players/*.filler
do
	let "mapnu = 0"
	if [ $playernu == 0 ]
	then player='abanlin'
	elif [ $playernu == 1 ]
	then player='carli'
	elif [ $playernu == 2 ]
	then player='champely'
	elif [ $playernu == 3 ]
	then player='grati'
	elif [ $playernu == 4 ]
	then player='hcao'
	else
		player='superjeannot'
	fi
	for m in ./../vm_filler/maps/map*
	do
		let "count = 0"
		for n in `seq 1 5`
		do
			./../vm_filler/filler_vm -q -p1 ./../*.filler -p2 "$f" -f "$m" > quiet
			line=`grep won filler.trace`
			echo "$line"
			if [ "$line" = './../femaury.filler won' ];
			then let "count = $count + 1"
			fi
		done
		for n in `seq 1 5`
		do
			./../vm_filler/filler_vm -q -p2 ./../*.filler -p1 "$f" -f "$m" > quiet
			line=`grep won filler.trace`
			echo "$line"
			if [ "$line" = './../femaury.filler won' ];
			then let "count = $count + 1"
			fi
		done
		let "win = ($count * 100) / 10"
		if [ $win -ge 60 ];
		then echo ${GREEN}$win% win against $player on map $mapnu ${NC}
		else
			echo ${RED}$win% win against $player on map $mapnu ${NC}
		fi
		let "mapnu = $mapnu + 1"
		if [ $mapnu == 3 ];
		then break
		fi
	done
	let "playernu = $playernu + 1"
done
