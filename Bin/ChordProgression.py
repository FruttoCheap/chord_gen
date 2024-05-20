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
    for i in range(0, len(line)-1):
        track.append(Message('note_on', note=notes[line[i]], velocity=100, time=0))
    k = 1
    for i in range(0, len(line)-1):
        track.append(Message('note_off', note=notes[line[i]], velocity=100, time=k*1920))
        k = 0

mid.save("Output/progression.mid")