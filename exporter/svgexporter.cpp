#include "svgexporter.h"

#include <QtGui>
#include <QSvgGenerator>

bool SVGExporter::exporting(QGraphicsView *view, QString filepath)
{
    if(view->scene()){
        QSvgGenerator generator;
        generator.setFileName(filepath);
        generator.setSize( QSize(view->scene()->width(), view->scene()->height()) );
        generator.setViewBox( QRect(0, 0, view->scene()->width(), view->scene()->height()) );
        generator.setTitle(QObject::trUtf8("Dependency graph"));
        generator.setDescription(QObject::trUtf8("Generated by DependenciesAnnotator"));

        QPainter svgPainter(&generator);
        svgPainter.setRenderHint(QPainter::HighQualityAntialiasing, true);
        view->scene()->render(&svgPainter);
        return true;
    }else
        return false;
}
