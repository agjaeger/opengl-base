
#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include <QDate>
#include <QLocale>

#include "propeditor/qtgroupboxpropertybrowser.h"
#include "propeditor/qtpropertymanager.h"
#include "propeditor/qtvariantproperty.h"

namespace extgraphics {
	class ExtGraphicsWindow : public QMainWindow {
		public:
			QAction *actionRender;
			QWidget *centralWidget;
			QMenuBar *menuBar;
			QMenu *menuFile;
			QStatusBar *statusBar;
			
			QtVariantPropertyManager *variantManager = new QtVariantPropertyManager();
			QtGroupBoxPropertyBrowser *variantEditor = new QtGroupBoxPropertyBrowser();
			
			ExtGraphicsWindow(QWidget *parent = 0) {
				setupUi(this);
			}
			
			void setupUi(QMainWindow *ExtGraphicsWindow) {
				if (ExtGraphicsWindow->objectName().isEmpty())
					ExtGraphicsWindow->setObjectName(QStringLiteral("ExtGraphicsWindow"));

				ExtGraphicsWindow->resize(400, 300);
				actionRender = new QAction(ExtGraphicsWindow);
				actionRender->setObjectName(QStringLiteral("actionRender"));

				centralWidget = new QWidget(ExtGraphicsWindow);
				centralWidget->setObjectName(QStringLiteral("centralWidget"));
				ExtGraphicsWindow->setCentralWidget(centralWidget);
				
				menuBar = new QMenuBar(ExtGraphicsWindow);
				menuBar->setObjectName(QStringLiteral("menuBar"));
				menuBar->setGeometry(QRect(0, 0, 400, 22));

				menuFile = new QMenu(menuBar);
				menuFile->setObjectName(QStringLiteral("menuFile"));
				ExtGraphicsWindow->setMenuBar(menuBar);

				statusBar = new QStatusBar(ExtGraphicsWindow);
				statusBar->setObjectName(QStringLiteral("statusBar"));
				ExtGraphicsWindow->setStatusBar(statusBar);

				menuBar->addAction(menuFile->menuAction());
				menuFile->addAction(actionRender);

				QtVariantEditorFactory *variantFactory = new QtVariantEditorFactory();
				variantEditor->setFactoryForManager(variantManager, variantFactory);
				//variantEditor->addProperty(topItem);
				////variantEditor->setPropertiesWithoutValueMarked(true);
				//variantEditor->setRootIsDecorated(false);

				ExtGraphicsWindow->setCentralWidget(variantEditor);

				retranslateUi(ExtGraphicsWindow);

				QMetaObject::connectSlotsByName(ExtGraphicsWindow);
			}

			void retranslateUi(QMainWindow *ExtGraphicsWindow) {
				ExtGraphicsWindow->setWindowTitle(QApplication::translate("ExtGraphicsWindow", "ExtGraphicsWindow", nullptr));
				actionRender->setText(QApplication::translate("ExtGraphicsWindow", "Render", nullptr));
				menuFile->setTitle(QApplication::translate("ExtGraphicsWindow", "File", nullptr));
			} 
	};
};