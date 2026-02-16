/* * [カスタムコード] アプリケーション層
 * SYS1の要件：1000ルクス未満で点灯、2000ルクス以上で消灯
 */

extern int IlluminanceValue;
extern void Set_Hardware_Light(int status);
extern int Received_EmergencyFlag;

/* 修正版ロジック */
void Control_Headlight_Logic() {
	// 修正：緊急フラグが「1（有効）」かつ「確定」している場合のみ点滅
    // 前回のコードでは判定が甘かったと仮定
    if (Received_EmergencyFlag == 1) { 
        printf("APP: EMERGENCY MODE - High priority flashing!\n");
        return; // 緊急時は通常の照度判定をスキップ
    }
    // 通常の照度判定（以下、既存ロジック）
	// SYS1に基づく判定ロジック
    if (IlluminanceValue < 1000) {
        Set_Hardware_Light(1); // 点灯
    } 
    else if (IlluminanceValue >= 2000) {
        Set_Hardware_Light(0); // 消灯
    }

	// 追加：急ブレーキ連携（SYS1要件）
    if (Received_EmergencyFlag == 1) {
        printf("APP: Emergency Flashing ACTIVE!\n");
    }
	
}


