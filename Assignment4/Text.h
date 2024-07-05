#ifndef TEXT_H
#define TEXT_H

class Text
{
public:
	Text();
	~Text();
	char** getText(void) const;
	void setText(char** newText);
	int getCurRow(void);
	void setCurRow(int row);
	int getColumnAmount(void);
	void setColumnAmount(int columns);
	int getRowsAmount(void);
	int setRowsAmount(int rows);
	int getBufferSize(void);
	void reallocColumns(void);
private:
	const size_t bufferSize = 256;
	char** text;
	int columnAmount = 256;
	int rowsAmount = 10;
	int curRow = 0;
};

#endif TEXT_H