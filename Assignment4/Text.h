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
	void setRowsAmount(int rows);
	int const getBufferSize(void);
	void reallocCollumns(void);
	void reallocRows(void);
private:
	size_t bufferSize = 256;
	char** text;
	int columnAmount;
	int rowsAmount;
	int curRow;
};

#endif TEXT_H