// $Id: mapimgform.h,v 1.1 2005/01/14 16:18:49 rbuehler Exp $


/****************************************************************************
** Form interface generated from reading ui file 'mapimgform.ui'
**
** Created: Thu Jul 29 12:27:35 2004
**      by: The User Interface Compiler ($Id: mapimgform.h,v 1.1 2005/01/14 16:18:49 rbuehler Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef mapimgFORM_H
#define mapimgFORM_H

#include <qvariant.h>
#include <qmainwindow.h>
#include <qmessagebox.h>

class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QPopupMenu;
class QToolBar;
class QWidgetStack;
class QImgFrame;
class QInfoFrame;
class RasterInfo;

class mapimgForm : public QMainWindow
{
   Q_OBJECT

public:
   mapimgForm( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
   ~mapimgForm();
   void dragEnterEvent( QDragEnterEvent *evt );
   void dropEvent( QDropEvent *evt );
   bool openFile( QString &inFile );

protected:
   QHBoxLayout    *formLayout;

protected slots:
   void inOpenClicked();
   void inSaveClicked();
   void previewProjClicked();
   void outSaveClicked();
   void editAuthor();
   void aboutClicked();
   void showAboutQt(){QMessageBox::aboutQt( this );}

private:
   void callmapimg( RasterInfo input, RasterInfo output );

   QMenuBar       *menuBar;
   QToolBar       *toolBar;

   QPopupMenu     *File;
   QAction        *exitAction;
   QAction        *bigAction;

   QPopupMenu     *Options;
   QAction        *authAction;

   QAction        *inInfoAction;
   QAction        *inOpenAction;
   QAction        *inSaveAction;
   QInfoFrame     *inInfoFrame;

   QPopupMenu     *Preview;
   QAction        *viewShowAction;
   QAction        *viewResampleAction;
   QAction        *previewProjAction;
   QImgFrame      *imgFrame;

   QAction        *outInfoAction;
   QAction        *outSaveAction;
   QInfoFrame     *outInfoFrame;

   QPopupMenu     *Help;
   QAction        *aboutAction;
   QAction        *aboutQtAction;

   QString inPath;
   QString outPath;
   QString authName;
   QString authCompany;
   QString authEmail;

   QString imgName;
   bool imgSet; //Has the user opened a .img file?
      //Used to determine wether or not to save .info files when the user says to
   bool newInfo; //Is the user generating a new .xml file for the .img?
};

#endif // mapimgFORM_H