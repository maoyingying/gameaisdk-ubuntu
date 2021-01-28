/*
 * This source code file is licensed under the GNU General Public License Version 3.
 * For full details, please refer to the file "LICENSE.txt" which is provided as part of this source code package.
 * Copyright (C) 2020 THL A29 Limited, a Tencent company.  All rights reserved.
 */

#ifndef SEND_ACTION_H_
#define SEND_ACTION_H_

#include "Protobuf/common.pb.h"
#include "UI/Src/Communicate/DataComm.h"
#include "UI/Src/UITypes.h"

class CSendAction
{
public:
    CSendAction();
    ~CSendAction();
    /*!
     * @brief ���͵������Э���
     * @param[in]stFramectx
     * @param[in]stSrcUIState
     * @param[in]stDstActionState
     * @return true��ʾ�ɹ���false��ʾʧ��
     */
    bool SendClickAction(const tagFrameContext &stFramectx, const tagUIState &stSrcUIState,
                         tagActionState &stDstActionState);

    /*!
     * @brief ���͵������Э���
     * @param[in]eGameState
     * @param[in]nID
     * @returnת�����״̬
     */
    GAMESTATEENUM MapState(const enGameState eGameState, const int nID);

    /*!
     * @brief ����Э���
     * @param[in]stFramectx
     * @param[in]pt1
     * @param[in]pt2
     * @param[in]uID
     * @param[in]stDstActionState
     * @param[in]eMsgState
     * @param[in]uiMsg
     * @param[in]nSleepTimeMS:�����궯����ĵȴ�ʱ��
     * @return true��ʾ�ɹ���false��ʾʧ��
     */
    bool SendActionMsg(const tagFrameContext &stFramectx, const cv::Point pt1, const cv::Point pt2, const int uID,
                       GAMESTATEENUM eMsgState, tagMessage &uiMsg, const int nSleepTimeMS = 100);

    /*!
     * @brief ������ק����Э���
     * @param[in]stFramectx��ͼ��֡��Ϣ
     * @param[in]stSrcUIState��UI״̬
     * @param[in]stDstActionState1����ק���
     * @param[in]stDstActionState2����ק�յ�
     * @return true��ʾ�ɹ���false��ʾʧ��
     */
    bool SendDragAction(const tagFrameContext &stFramectx, const tagUIState &stSrcUIState,
                        const tagActionState &stDstActionState1, const tagActionState &stDstActionState2);

    /*!
     * @brief ��ȡ��������
     * @param[in]josnValue
     * @param[out]stState1
     * @param[out]stDstActionState1����ק���
     * @param[out]stState2����ק�յ�
     * @return true��ʾ�ɹ���false��ʾʧ��
    */
    void ReadActionJsonValue(const Json::Value &josnValue, tagActionState &stState1, tagActionState &stState2);
    /*!
     * @brief ��ȡ��������
     * @param[in]inPoint
     * @param[in]inImgSize
     * @param[in]outImgSize
     * @param[out]outPoint
    */
    void RestoreActionPoint(const cv::Point inPoint, const cv::Size inImgSize,
                            const cv::Size outImgSize, cv::Point &outPoint);

    /*!
     * @brief �����������
     * @param[in]oFrame��ͼ��֡
     * @param[in]actionPoint1����һ�����λ��(�������ʱ��ֻ��Ҫ��һ��λ�ã��ڶ������λ����Ч
       ��ק����ʱ����һ�����λ�ñ�ʾ��ק����㣬�ڶ������λ�ñ�ʾ��ק���յ�)
     * @param[in]actionPoint2���ڶ������λ��(�������ʱ��ֻ��Ҫ��һ��λ��)
     * @param[in]nActionID����Ϸ״̬
     */
    void PaintAction(cv::Mat oFrame, cv::Point actionPoint1, cv::Point actionPoint2, int nActionID,
                     GAMESTATEENUM eMsgState = PB_STATE_NONE);
    /*!
     * @brief ��������ģʽ
     * @param[in]eTestMode
     */
    void SetTestMode(const ETestMode eTestMode);

    /*!
     * @brief ������Ϸ״̬
     * @param[in]eTestMode
     */
    void SetGameState(const enGameState eGameState);

    /*!
     * @brief �����Ƿ�������Ϸ���
     * @param[in]eTestMode
     */
    void SetShowResult(const bool bShowResult);

private:
    ETestMode     m_eTestMode;
    GAMESTATEENUM m_eMsgState;
    enGameState   m_eGameState;

    bool m_bShowResult;
};

#endif // SEND_ACTION_H_
