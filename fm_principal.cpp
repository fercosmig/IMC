#include "fm_principal.h"
#include "ui_fm_principal.h"

fm_principal::fm_principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fm_principal)
{
    ui->setupUi(this);
}

fm_principal::~fm_principal()
{
    delete ui;
}

/***************************************
 *
 * MINHAS FUNÇÕES
 *
 ***************************************/

void fm_principal::limpaFormulario()
{
    // LIMPA FORMULÁRIO
    ui->lineEdit_altura->clear();
    ui->lineEdit_massa->clear();
    ui->lcdNumber_imc->display(0);
    ui->label_mensagem->clear();
    ui->lcdNumber_massa_minimo->display(0);
    ui->lcdNumber_massa_maximo->display(0);
    ui->lineEdit_altura->setFocus();
}

double fm_principal::calculaIMC(double altura, double massa)
{
    double imc; // imc = massa / altura²

    imc = massa / qPow(altura, 2);

    return imc;
}

QString fm_principal::recuperaMensagem(double imc)
{
    QString mensagem;

    if (imc >=0 && imc <= 16)
        mensagem = "Magreza grave!";

    if(imc > 16 && imc <= 17)
        mensagem = "Magreza moderada!";

    if (imc >17 && imc <= 18.6)
        mensagem = "Magreza leve!";

    if (imc > 18.6 && imc <= 25)
        mensagem = "Peso ideal, vá curtir a vida!";

    if (imc > 25 && imc <= 30)
        mensagem = "Sobrepeso!";

    if (imc > 30 && imc <= 35)
        mensagem = "Obesidade grau I";

    if (imc > 35 && imc <= 40)
        mensagem = "Obesidade grau II ou Severa!";

    if (imc > 40)
        mensagem = "Obesidade morbida!";

    return mensagem;
}

double fm_principal::calculaMassaMinima(double altura)
{
#define IMC_MINIMO 18.6

    double resposta;

    resposta = IMC_MINIMO * qPow(altura, 2);

    return resposta;
}

double fm_principal::calculaMassaMaxima(double altura)
{
#define IMC_MAXIMO 25

    double resposta;

    resposta = IMC_MAXIMO * qPow(altura, 2);

    return resposta;
}

/***************************************
 *
 * SLOTS
 *
 ***************************************/

void fm_principal::on_pushButton_limpar_clicked()
{
    limpaFormulario();
}

void fm_principal::on_actionSair_triggered()
{
    // FECHA O APLICATIVO
    QApplication::quit();
}

void fm_principal::on_actionSobre_triggered()
{
    fm_sobre f_sobre;
    f_sobre.exec();
}

void fm_principal::on_pushButton_calcular_clicked()
{
    double altura, massa, imc, massa_minima, massa_maxima;
    QString mensagem;

    altura = ui->lineEdit_altura->text().replace(",", ".").toDouble();
    massa = ui->lineEdit_massa->text().replace(",", ".").toDouble();

    imc = calculaIMC(altura, massa);
    ui->lcdNumber_imc->display(imc);

    mensagem = recuperaMensagem(imc);
    ui->label_mensagem->setText(mensagem);

    massa_minima = calculaMassaMinima(altura);
    ui->lcdNumber_massa_minimo->display(massa_minima);

    massa_maxima = calculaMassaMaxima(altura);
    ui->lcdNumber_massa_maximo->display(massa_maxima);
}

void fm_principal::on_pushButton_fechar_clicked()
{
    QApplication::quit();
}

