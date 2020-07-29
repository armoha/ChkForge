#ifndef MAPVIEW_H
#define MAPVIEW_H

#include "DockWidgetWrapper.h"
#include "ui_mapview.h"
#include <QImage>
#include <QTimer>
#include <QGraphicsScene>
#include <memory>

#include <QVector>
#include <Qrgb>

struct main_t;

class MapView : public DockWidgetWrapper<Ui::MapView>
{
  Q_OBJECT

public:
  explicit MapView(QWidget *parent = nullptr);
  virtual ~MapView();

  void init();

  void move_minimap(int x, int y);
  void draw_minimap(uint8_t* data, size_t data_pitch, size_t surface_width, size_t surface_height);
  QVector<QRgb> get_palette();

  int map_width();
  int map_height();

private:
  QImage buffer;
  main_t* bw = nullptr;
  std::unique_ptr<QTimer> timer;

  virtual void changeEvent(QEvent* event) override;

  virtual bool eventFilter(QObject* obj, QEvent* event) override;
  void paint_surface(QWidget* obj, QPaintEvent* paintEvent);

  void resizeSurface(const QSize& newSize);

private slots:
  void onCloseRequested();
  void updateLogic();

};

#endif // MAPVIEW_H
