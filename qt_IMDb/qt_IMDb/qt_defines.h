#ifndef QT_DEFINES_H
#define QT_DEFINES_H


#define SET_TABLE_COLUMN_WIDTH(tableView) \
	ui.tableView->setColumnWidth( TITLE,				250 ); \
	ui.tableView->setColumnWidth( DIRECTORS,			150 ); \
	ui.tableView->setColumnWidth( IMDB_RATING,		30 );  \
	ui.tableView->setColumnWidth( YOU_RATED,			30 );  \
	ui.tableView->setColumnWidth( YEAR,				40 );  \
	ui.tableView->setColumnWidth( RUNTIME,			30 );  \
	ui.tableView->setColumnWidth( GENRES,			100 ); \
	ui.tableView->setColumnWidth( NUM_VOTES,			50 );  \
	ui.tableView->setColumnWidth( TITLE_TYPE,		80 );  \
	ui.tableView->setColumnWidth( RELEASE_DATE,		75 );  \
	ui.tableView->setColumnWidth( URL,				225 ); \
	ui.tableView->setColumnWidth( CREATED,			100 ); \
	ui.tableView->setColumnWidth( MODIFIED,			100 ); \
	ui.tableView->setColumnWidth( POSITION,			40 );  \
	ui.tableView->setColumnWidth( CONSTID,			75 );  \
	ui.tableView->setColumnWidth( DESCRIPTION,		300 ); \


#define SET_HEADER_LABELS(HeaderLabels) \
		HeaderLabels << "Title" << "Directors" << \
"IMDb Rating" << "You rated" << "Year" << \
"Runtime (mins)" << "Genres" << "Num. Votes" << \
"Title type" << "Release Date (month/day/year)" << \
"URL" << "Created" << "Modified" << \
"Position" << "ConstID" << "Description"; \







#endif