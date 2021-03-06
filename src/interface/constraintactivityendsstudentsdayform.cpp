/***************************************************************************
                          constraintactivityendsstudentsdayform.cpp  -  description
                             -------------------
    begin                : Sept 14, 2007
    copyright            : (C) 2007 by Lalescu Liviu
    email                : Please see https://lalescu.ro/liviu/ for details about contacting Liviu Lalescu (in particular, you can find here the e-mail address)
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU Affero General Public License as        *
 *   published by the Free Software Foundation, either version 3 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 ***************************************************************************/

#include "constraintactivityendsstudentsdayform.h"
#include "addconstraintactivityendsstudentsdayform.h"
#include "modifyconstraintactivityendsstudentsdayform.h"

#include "teacherstudentsetsubjectactivitytag_filterwidget.h"

#include "centerwidgetonscreen.h"

ConstraintActivityEndsStudentsDayForm::ConstraintActivityEndsStudentsDayForm(QWidget* parent): TimeConstraintBaseDialog(parent)
{
	//: This is the title of the dialog to see the list of all constraints of this type
	setWindowTitle(QCoreApplication::translate("ConstraintActivityEndsStudentsDayForm_template", "Constraints activity ends students day"));

	TeacherStudentSetSubjectActivityTag_FilterWidget *filterWidget = new TeacherStudentSetSubjectActivityTag_FilterWidget(gt.rules);
	filterWidget->setTeachersVisible(true);
	filterWidget->setStudentSetsVisible(true);
	filterWidget->setSubjectsVisible(true);
	filterWidget->setActivityTagsVisible(true);
	setFilterWidget(filterWidget);

	connect(filterWidget, &TeacherStudentSetSubjectActivityTag_FilterWidget::FilterChanged, this, &ConstraintActivityEndsStudentsDayForm::filterChanged);

	restoreFETDialogGeometry(this);
	this->filterChanged();
}

ConstraintActivityEndsStudentsDayForm::~ConstraintActivityEndsStudentsDayForm()
{
	saveFETDialogGeometry(this);
}

bool ConstraintActivityEndsStudentsDayForm::filterOk(const TimeConstraint* ctr) const
{
	if(ctr->type!=CONSTRAINT_ACTIVITY_ENDS_STUDENTS_DAY)
		return false;
		
	const ConstraintActivityEndsStudentsDay* c=(const ConstraintActivityEndsStudentsDay*) ctr;
	int id=c->activityId;
	const Activity* act=NULL;
	for(const Activity* a : qAsConst(gt.rules.activitiesList)) {
		if(a->id==id) {
			act=a;
			break;
		}
	}
	assert(act != NULL);

	const TeacherStudentSetSubjectActivityTag_FilterWidget * filterWidget = static_cast<TeacherStudentSetSubjectActivityTag_FilterWidget*>(getFilterWidget());
	return filterWidget->filterActivity(act);
}

QDialog * ConstraintActivityEndsStudentsDayForm::createAddDialog()
{
	return new AddConstraintActivityEndsStudentsDayForm(this);
}

QDialog * ConstraintActivityEndsStudentsDayForm::createModifyDialog(TimeConstraint *ctr)
{
	return new ModifyConstraintActivityEndsStudentsDayForm(this, (ConstraintActivityEndsStudentsDay*)ctr);
}
