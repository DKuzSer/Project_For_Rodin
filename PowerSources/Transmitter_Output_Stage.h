#ifndef TRANSMITTER_OUTPUT_STAGE_H
#define TRANSMITTER_OUTPUT_STAGE_H

#include <QWidget>

namespace Ui {
class Transmitter_Output_Stage;
}

class Transmitter_Output_Stage : public QWidget
{
    Q_OBJECT

public:
    explicit Transmitter_Output_Stage(QWidget *parent = nullptr);
    ~Transmitter_Output_Stage();

private:
    Ui::Transmitter_Output_Stage *ui;
};

#endif // TRANSMITTER_OUTPUT_STAGE_H
