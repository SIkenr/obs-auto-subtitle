/*
obs-auto-subtitle
 Copyright (C) 2019-2020 Yibai Zhang

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; If not, see <https://www.gnu.org/licenses/>
*/

#ifndef OBS_AUTOSUB_XFTRANS_BUILDER_H
#define OBS_AUTOSUB_XFTRANS_BUILDER_H

#include <QString>

#include "TransBuilderBase.h"
#include "../vendor/Trans/XFTrans.h"

class XFTransBuilder : public TransBuilderBase {
public:
    void getProperties(obs_properties_t *props);
    void showProperties(obs_properties_t *props);
    void hideProperties(obs_properties_t *props);
    void updateSettings(obs_data_t *settings);
    void getDefaults(obs_data_t *settings);
    void setNormalTrans();
    void setNiuTrans();
    TransBase *build();

protected:
    static const LangList *langList;

private:
    QString appId;
    QString apiKey;
    QString apiSecret;
    bool isNiuTrans = false;
    bool needBuild = false;
};

#define PROP_TRANS_XF_APPID _PROP("xf_appid")
#define PROP_TRANS_XF_APIKEY _PROP("xf_apikey")
#define PROP_TRANS_XF_APISECRET _PROP("xf_apisecret")
#define PROP_TRANS_XF_FROMLANG _PROP("xf_fromlang")
#define PROP_TRANS_XF_TOLANG _PROP("xf_tolang")

#endif

