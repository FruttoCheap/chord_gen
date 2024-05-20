target:
	gcc -o gen FollowedChordGen.c
	./gen A 1 > tmp.txt
	sleep 1
	python3 ChordProgression.py
	python3 Bass.py
	rm -rf *.o gen tmp.txt
	mv bass.mid progression.mid ../MIDI
	exit
