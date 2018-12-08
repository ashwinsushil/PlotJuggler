#ifndef AddCustomPlotDialog_H
#define AddCustomPlotDialog_H

#include <QDialog>
#include <QListWidgetItem>
#include <qwt_plot_curve.h>
#include "PlotJuggler/plotdata.h"
#include "custom_plot.h"

namespace Ui {
class AddCustomPlotDialog;
}

class AddCustomPlotDialog : public QDialog
{
    Q_OBJECT

    struct SnippetData{
        QString name;
        QString globalVars;
        QString equation;
    };

public:
    explicit AddCustomPlotDialog(PlotDataMapRef &plotMapData,
                               const std::vector<CustomPlotPtr>& mapped_custom_plots,
                               QWidget *parent);
    virtual ~AddCustomPlotDialog() override;

    void setLinkedPlotName(const QString &linkedPlotName);
    virtual void accept() override;

    QString getLinkedData() const;
    QString getGlobalVars() const;
    QString getEquation() const;
    QString getName() const;
    const PlotData& getPlotData() const;
    void editExistingPlot(CustomPlotPtr data);
    CustomPlotPtr getCustomPlotData() const;

private slots:

    void on_curvesListWidget_doubleClicked(const QModelIndex &index);

    void on_snippetsListSaved_currentRowChanged(int currentRow);

    void on_snippetsListSaved_doubleClicked(const QModelIndex &index);

    void on_snippetsListRecent_currentRowChanged(int currentRow);

    void on_snippetsListRecent_doubleClicked(const QModelIndex &index);

    void recentContextMenu(const QPoint &pos);

    void on_nameLineEdit_textChanged(const QString &arg1);

private:
    void createSnippets();


    PlotDataMapRef &_plot_map_data;
    const std::vector<CustomPlotPtr> &_custom_plots;
    Ui::AddCustomPlotDialog *ui;

    CustomPlotPtr _plot;
    bool _is_new;

    std::vector<SnippetData> _snipped_examples;
    std::vector<SnippetData> _snipped_recent;
};

#endif // AddCustomPlotDialog_H
