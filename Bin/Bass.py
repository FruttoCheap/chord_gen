from mido import MidiFile, Message, MidiTrack

notes = {
    "C": 60,
    "c": 61,
    "D": 62,
    "d": 63,
    "E": 64,
    "F": 65,
    "f": 66,
    "G": 67,
    "g": 68,
    "A": 69,
    "b": 70,
    "B": 71
}

mid = MidiFile()
track = MidiTrack()
mid.tracks.append(track)

file=open("tmp.txt", "r")
for line in file:
    track.append(Message('note_on', note=notes[line[0]], velocity=100, time=0))
    track.append(Message('note_off', note=notes[line[0]], velocity=100, time=1920))

mid.save("Output/bass.mid")