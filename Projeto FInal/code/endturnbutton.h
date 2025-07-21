#ifndef ENDTURNBUTTON_H
#define ENDTURNBUTTON_H

#include "graphicitem.h"

class EndTurnButton : public GraphicItem
{
    Q_OBJECT
public:
    EndTurnButton(const QString& imagePath, QGraphicsItem* parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void clicked();

};

#endif // ENDTURNBUTTON_H
