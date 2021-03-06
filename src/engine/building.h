//
//
// Description: This file is part of FET
//
//
// Author: Liviu Lalescu <Please see https://lalescu.ro/liviu/ for details about contacting Liviu Lalescu (in particular, you can find here the e-mail address)>
// Copyright (C) 2005 Liviu Lalescu <https://lalescu.ro/liviu/>
//
/***************************************************************************
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU Affero General Public License as        *
 *   published by the Free Software Foundation, either version 3 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 ***************************************************************************/

#ifndef BUILDING_H
#define BUILDING_H

#include <QCoreApplication>

#include <QString>
#include <QList>

class Building;
class Rules;

typedef QList<Building*> BuildingsList;

/**
This class represents a building

@author Liviu Lalescu
*/
class Building{
	Q_DECLARE_TR_FUNCTIONS(Building)

public:
	QString name;
	
	QString comments;

	Building();
	~Building();
	
	void computeInternalStructure(Rules& r);
	
	QString getXmlDescription() const;
	QString getDescription() const;
	QString getDetailedDescription() const;
	QString getDetailedDescriptionWithConstraints(const Rules& r) const;
};

bool buildingsAscending(const Building* b1, const Building* b2);

#endif
