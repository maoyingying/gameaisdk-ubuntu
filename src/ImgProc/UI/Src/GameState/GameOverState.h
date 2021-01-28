/*
 * This source code file is licensed under the GNU General Public License Version 3.
 * For full details, please refer to the file "LICENSE.txt" which is provided as part of this source code package.
 * Copyright (C) 2020 THL A29 Limited, a Tencent company.  All rights reserved.
 */

#ifndef GAME_OVER_STATE_H_
#define GAME_OVER_STATE_H_

#include "Comm/Utils/TSingleton.h"
#include "UI/Src/GameState/UIState.h"


class CGameOverState : public TSingleton<CGameOverState>, public CUIState
{
public:
    CGameOverState();
    virtual ~CGameOverState();

    /*!
     * @brief 游戏结束状态处理图像帧
     * @param[in] stFrameCtx　当前帧信息
     * @param[in] pContext
     */
    virtual void Handle(const tagFrameContext &stFrameCtx, CContext *pContext);
    virtual int Handle(const tagFrameContext &stFrameCtx, CContext *pContext, int getState);
};


#endif // GAME_OVER_STATE_H_
