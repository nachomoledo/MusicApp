#ifndef RANDOMNOTEGENERATOR_H
#define RANDOMNOTEGENERATOR_H

#include <map>
#include <QBasicTimer>
#include <QTimer>
#include <QObject>
#include <string>
#include <QString>
#include<vector>

enum ModoPrograma { notas, acordes };

class RandomNoteGenerator : public QObject
{
  Q_OBJECT
private:
  std::vector<std::pair<std::string, std::string>> m_vectorNotas;
  std::vector<int> m_vectorNotasRemanentes;
  std::vector<std::pair<std::string, std::string>> m_vectorAcordes;
  std::vector<int> m_vectorAcordesRemanentes;
  bool sinRepetidas = true;
  ModoPrograma modoPrograma;
  std::vector<int> m_vectorIndicesNotas;
  std::vector<int> m_vectorIndicesAcordes;
  std::map<std::string, std::string> *m_map;

  QTimer *m_timer;

public:
  RandomNoteGenerator(QObject *parent = nullptr);
  Q_INVOKABLE void startTimer(void);
  Q_INVOKABLE QString getRandomNote();
  Q_INVOKABLE QString getRandomChord();
  Q_INVOKABLE void setModoPrograma(int i);

public slots:
  void printRandomNote();

};

#endif // RANDOMNOTEGENERATOR_H
