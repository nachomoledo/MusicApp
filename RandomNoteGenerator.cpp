#include "RandomNoteGenerator.h"
#include <iostream>
#include <utility>
#include <QDebug>
#include <cstdlib>

RandomNoteGenerator::RandomNoteGenerator(QObject *parent) : QObject(parent)
{ 
  m_vectorNotas.push_back({"A","La"});
  m_vectorNotas.push_back({"B","Si"});
  m_vectorNotas.push_back({"C","Do"});
  m_vectorNotas.push_back({"D","Re"});
  m_vectorNotas.push_back({"E","Mi"});
  m_vectorNotas.push_back({"F","Fa"});
  m_vectorNotas.push_back({"G","Sol"});

  unsigned int i = 0;

  for (i = 0; i < m_vectorNotas.size(); i++)
  {
    m_vectorIndicesNotas.push_back(i);
  }

  m_vectorAcordes.push_back({"C","DoM"});
  m_vectorAcordes.push_back({"Dm","Rem"});
  m_vectorAcordes.push_back({"Em","Mim"});
  m_vectorAcordes.push_back({"F","FaM"});
  m_vectorAcordes.push_back({"G","SolM"});
  m_vectorAcordes.push_back({"Am","Lam"});
//  m_vectorAcordes.push_back({"Bb5","Sib5"});

  for (i = 0; i < m_vectorAcordes.size(); i++)
  {
    m_vectorIndicesAcordes.push_back(i);
  }

  modoPrograma = notas;

  m_timer = new QTimer(this);

  connect(m_timer, &QTimer::timeout, this, &RandomNoteGenerator::printRandomNote);

  srand (time(nullptr));

}

void RandomNoteGenerator::startTimer()
{
  m_timer->start(1000);
}

void RandomNoteGenerator::printRandomNote()
{
  int randNum = rand() % m_vectorNotas.size();
  qDebug() << m_vectorNotas.at(randNum).first.c_str() << " - " << m_vectorNotas.at(randNum).second.c_str();
}

void RandomNoteGenerator::setModoPrograma(int i)
{
  if(modoPrograma != static_cast<ModoPrograma>(i))
    {
      modoPrograma = static_cast<ModoPrograma>(i);
    }
}

QString RandomNoteGenerator::getRandomNote()
{
  if (m_vectorNotasRemanentes.empty())
  {
    m_vectorNotasRemanentes = m_vectorIndicesNotas;
  }

  int randNum = rand() % m_vectorNotasRemanentes.size();
  QString retValue;
  retValue = QString("%1 - %2").arg(m_vectorNotas.at(m_vectorNotasRemanentes.at(randNum)).first.c_str()).arg(m_vectorNotas.at(m_vectorNotasRemanentes.at(randNum)).second.c_str());
  m_vectorNotasRemanentes.erase(m_vectorNotasRemanentes.begin() + randNum);
  return retValue ;
}

QString RandomNoteGenerator::getRandomChord()
{
  if (m_vectorAcordesRemanentes.empty())
  {
    m_vectorAcordesRemanentes = m_vectorIndicesAcordes;
  }

  int randNum = rand() % m_vectorAcordesRemanentes.size();
  QString retValue;
  retValue = QString("%1 - %2").arg(m_vectorAcordes.at(m_vectorAcordesRemanentes.at(randNum)).first.c_str()).arg(m_vectorAcordes.at(m_vectorAcordesRemanentes.at(randNum)).second.c_str());
  m_vectorAcordesRemanentes.erase(m_vectorAcordesRemanentes.begin() + randNum);
  return retValue ;
}
