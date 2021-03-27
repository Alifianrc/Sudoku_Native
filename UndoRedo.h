#include <stack>

// 

class UndoRedo {
private:
	struct TheData {
		int x, y, value;
	};

	std::stack<TheData> undo;
	std::stack<TheData> redo;

public:
	void PushUndoData(int i, int j, int val);
	void PushRedoData(int i, int j, int val);

	bool PopUndoData(int* i, int* j, int* val);
	bool PopRedoData(int* i, int* j, int* val);

	void ResetUndoData();
	void ResetRedoData();
};
