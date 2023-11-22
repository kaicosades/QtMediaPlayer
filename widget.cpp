#include "widget.h"
#include "ui_widget.h"

#include <QStyle>
#include <QFileDialog>
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //          buttons style:
    ui->pushButtonOpen->setIcon(style()->standardIcon(QStyle::SP_DriveCDIcon));     //user interface
    ui->pushButtonPrev->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->pushButtonPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->pushButtonStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButtonNext->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    ui->pushBattonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    //          player init:
    m_player = new QMediaPlayer(this);
    m_player->setVolume(70);
    ui->labelVolume->setText(QString("Volume: ").append(QString::number(m_player->volume())));//get не прописывается
    ui->horizontalSliderVolume->setValue(m_player->volume());
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonOpen_clicked()
{
    QString file = QFileDialog::getOpenFileName
            (
             this,          //родительское окно
             tr("Open file"),//заголовок окна диалога
             "C:\\Users\\user\\Desktop\\муз",       //рабочий каталог
             tr("Audio files (*.mp3 *.flac)")

                );
    ui->labelComposition->setText(file);
    m_player->setMedia(QUrl::fromLocalFile(file));
}


void Widget::on_horizontalSliderVolume_valueChanged(int value)
{
    m_player->setVolume(value);
    ui->labelVolume->setText(QString("Volume: ").append(QString::number(m_player->volume())));
}


void Widget::on_pushBattonPlay_clicked()
{
    m_player->play();
}

