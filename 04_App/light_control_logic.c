/* * [カスタムコード] アプリケーション層
 * SYS1の要件：1000ルクス未満で点灯、2000ルクス以上で消灯
 */

extern int IlluminanceValue;
extern void Set_Hardware_Light(int status);

void Control_Headlight_Logic() {
    // SYS1に基づく判定ロジック
    if (IlluminanceValue < 1000) {
        Set_Hardware_Light(1); // 点灯
    } 
    else if (IlluminanceValue >= 2000) {
        Set_Hardware_Light(0); // 消灯
    }
}


