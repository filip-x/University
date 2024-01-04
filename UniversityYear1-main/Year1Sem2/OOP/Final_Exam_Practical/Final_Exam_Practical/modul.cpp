#include "modul.h"
#include <QTableView>
#include <QBrush>
#include <QFont>
#include <QPainter>
#include <QLayout>
Model::Model(Service& stars_service, QObject* Parent) : QAbstractTableModel(Parent), service_stars(stars_service) { }

//Model::Model() { }
int Model::rowCount(const QModelIndex& parent) const
{
	auto data = service_stars.list2();
	int count_data  = data.size();
	return count_data;
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 5;//bcs there are 5 things :)

}

QVariant Model::data(const QModelIndex& index_for_list, int role) const
{
	int row = index_for_list.row();
	int column = index_for_list.column();
	auto data_of_stars = service_stars.list2();
	if (row == data_of_stars.size())
		return QVariant();

	Stars element = data_of_stars[row];
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		QString info;
		switch (column)
		{
		case 0:

			info = QString::fromStdString(element.get_name());
			return info;

		case 1:

			info = QString::fromStdString(element.get_constelation());
			return info;

		case 2:

			info = QString::fromStdString(std::to_string(element.get_ra()));
			return info;

		case 3:

			info = QString::fromStdString(std::to_string(element.get_dec()));
			return info;

		case 4:

			info = QString::fromStdString(std::to_string(element.get_diameter()));
			return info;

		default: break;
		}
	}
	if (role == Qt::FontRole)
	{
		
		return QVariant();
	}
	

	return QVariant{};

}

QVariant Model::headerData(int sections, Qt::Orientation way, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (way == Qt::Horizontal)
		{
			switch (sections)
			{
			case 0:
				return QString{ "Name" };
			case 1:
				return QString{ "Constellation" };
			case 2:
				return QString{ "RA" };
			case 3:
				return QString{ "Dec" };
			case 4:
				return QString{ "Diameter" };
			default:
				break;
			}
		}
	}
	if (role == Qt::FontRole)
	{
		return QVariant();
	}

	return QVariant{};
}

bool Model::setData(const QModelIndex& index_for_list, const QVariant& value, int role)
{
	return false;
}

Qt::ItemFlags Model::flags(const QModelIndex& index_for_list) const
{
	return Qt::ItemFlags();
}

void Model::reset()
{
	this->beginResetModel();
	this->endResetModel();
}

void Model::nofilter()
{
	filtered = false;
	reset();
}

void Model::filter(std::string NewFilterArg)
{
	FilterArg = NewFilterArg;
	filtered = true;
	reset();
}
