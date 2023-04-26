#include <QGuiApplication>
#include <QQmlApplicationEngine>

inline constexpr char const *kMainQmlPath = "qrc:/qml/main.qml";

auto main(int argc, char *argv[]) -> int {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(kMainQmlPath));

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return QGuiApplication::exec();
}

