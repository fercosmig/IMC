#ifndef FM_PRINCIPAL_H
#define FM_PRINCIPAL_H

#include <QMainWindow>
#include "fm_sobre.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class fm_principal;
}
QT_END_NAMESPACE

class fm_principal : public QMainWindow
{
    Q_OBJECT

public:
    fm_principal(QWidget *parent = nullptr);
    ~fm_principal();

    // MINHAS FUNÇÕES
    void limpaFormulario();
    double calculaIMC(double altura, double massa);
    QString recuperaMensagem(double imc);
    double calculaMassaMinima(double altura);
    double calculaMassaMaxima(double altura);

private slots:
    void on_pushButton_limpar_clicked();

    void on_actionSair_triggered();

    void on_actionSobre_triggered();

    void on_pushButton_calcular_clicked();

    void on_pushButton_fechar_clicked();

private:
    Ui::fm_principal *ui;
};
#endif // FM_PRINCIPAL_H
