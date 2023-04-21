#include "Notes.h"
#include <math.h>

NOTE_DEFINITION(NoteA)
NOTE_DEFINITION(NoteASharp)
NOTE_DEFINITION(NoteB)
NOTE_DEFINITION(NoteC)
NOTE_DEFINITION(NoteCSharp)
NOTE_DEFINITION(NoteD)
NOTE_DEFINITION(NoteDSharp)
NOTE_DEFINITION(NoteE)
NOTE_DEFINITION(NoteF)
NOTE_DEFINITION(NoteFSharp)
NOTE_DEFINITION(NoteG)
NOTE_DEFINITION(NoteGSharp)

//NoteA::NoteA(const octava_shift_t s) :
//	octava_shift_(s)
//{
//
//}
//
//auto NoteA::get_frequency() const noexcept -> frequency_t
//{
//	return FREQUENCY * pow(HALF_TONE, octava_shift_);
//}