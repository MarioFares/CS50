#ifndef QUERIES_H
#define QUERIES_H

#include <qsqldatabase.h>
#include <qsqlquery.h>

/*
 * All page must be of type quint32 = uint
 * All sizes must be of type quint64 = unsigned long long
 */

namespace queries {

extern QSqlDatabase db;
extern QSqlQuery query;

void connectToDatabase();

QString genExtQuery(QString entity, QString text);

QString genTagQuery(QString tags);

QString cleanTags(QString tags);

// Setup Tables Queries
void createEbooksTable();

void createSearchTable();

// Reset Tables Queries
void resetEbooksTableQuery();

void resetTags();

void resetSearchesTable();


// Select Queries
void selectFoldersQuery();

void selectAuthorsQuery();

void selectGenreQuery();

void selectSearchesQuery();

void selectPath();

void selectExt();

void selectTags();

void selectSearchCriteriaQuery(QString searchName);

void selectCountEbooks();

void selectNameBasedOnRowid(quint32 rowid);

void selectPathBasedonName(QString name);

void selectNameBasedOnString(QString stringToSearch = "%");

void selectAllBasedonName(QString name);

void selectNameBasedOnCriteria(QString folder, QString genre, QString author, QString tags, QString ext,
                                      quint32 fromPages, quint32 toPages, quint64 fromSize, quint64 toSize);

// Insert Queries
void insertBooksQuery(QString name, QString path, QString folder, QString ext, quint64 size,
                      quint32 pages, QString tags, QString genre, QString author);

void insertSearchQuery(QString searchName, QString folder, QString author, QString genre, QString tags,
                              QString ext, quint32 fromSize, quint32 toSize, QString sizeIn, quint32 fromPages, quint32 toPages);


// Update Queries
void updateBookQuery(QString oldName, QString newName, QString folder, QString genre,
                            QString author, quint32 pages, QString tags, QString path);


//Delete Queries
void deleteBook(QString fileName);

} // Namespace queries
#endif // QUERIES_H
