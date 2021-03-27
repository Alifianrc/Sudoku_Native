#include "UndoRedo.h"

//

void UndoRedo::PushUndoData(int i, int j, int val) {
	TheData temp;
	temp.x = i;
	temp.y = j;
	temp.value = val;

	undo.push(temp);
}
void UndoRedo::PushRedoData(int i, int j, int val) {
	TheData temp;
	temp.x = i;
	temp.y = j;
	temp.value = val;

	redo.push(temp);
}

bool UndoRedo::PopUndoData(int* i, int* j, int* val) {
	if (undo.empty() == true) {
		return false;
	}
	else {
		TheData temp = undo.top();
		undo.pop();

		*i = temp.x;
		*j = temp.y;
		*val = temp.value;

		return true;
	}
}
bool UndoRedo::PopRedoData(int* i, int* j, int* val) {
	if (redo.empty() == true) {
		return false;
	}
	else {
		TheData temp = redo.top();
		redo.pop();

		*i = temp.x;
		*j = temp.y;
		*val = temp.value;

		return true;
	}
}

void UndoRedo::ResetUndoData() {
	while (!undo.empty()) {
		undo.pop();
	}
}
void UndoRedo::ResetRedoData() {
	while (!redo.empty()) {
		redo.pop();
	}
}