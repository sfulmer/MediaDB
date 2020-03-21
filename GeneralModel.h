#pragma once

#include "Observable.h"

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace mediadb
        {
            namespace model
            {
                class GeneralModel : public Observable
                {
                    bool mbEditedFieldsBold, mbEditedFieldsItalicized, mbLabelsBold, mbLabelsItalicized;
                public:
                    GeneralModel();

                    bool areEditedFieldsBold() const;
                    bool areEditedFieldsItalicized() const;
                    bool areLabelsBold() const;
                    bool areLabelsItalicized() const;
                    void setEditedFieldsBold(const bool bEditableFieldsBold);
                    void setEditedFieldsItalicized(const bool bEditableFieldsItalicized);
                    void setLabelsBold(const bool bLabelsBold);
                    void setLabelsItalicized(const bool bLabelsItalicized);
                };
            }
        }
    }
}
