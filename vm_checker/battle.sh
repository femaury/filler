RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

for f in ./../vm_filler/players/*.filler
do
	let "mapnu = 0"
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
		let "win = 0"
		let "win = ($count * 200) / 10"
		if [ $win -ge 60 ];
		then echo ${GREEN}$win % of win against $f on map $mapnu as player 1.${NC}
		else
			echo ${RED}$win % of win against $f on map $mapnu as player 1.${NC}
		fi
		let "count = 0"
		for n in `seq 1 5`
		do
			./../vm_filler/filler_vm -q -p2 ./../*.filler -p1 "$f" -f "$m" > quiet
			line=`grep won filler.trace`
			echo "$line"
			if [ "$line" = './../femaury.filler won' ];
			then let "count = $count + 1"
			fi
		done
		let "win = 0"
		let "win = ($count * 200) / 10"
		if [ $win -ge 60 ];
		then echo ${GREEN}$win % of win against $f on map $mapnu as player 2. ${NC}
		else
			echo ${RED}$win % of win against $f on map $mapnu as player 2. ${NC}
		fi
		let "mapnu = $mapnu + 1"
	done
done
