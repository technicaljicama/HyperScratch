
#include "sprite.h"
#include "costume.h"

#include "blocks.h"

#include "stage.h"

inline int gWhileLoop = -1;

inline std::string var_brian10 = "1";
inline std::string var_willie3 = "0";
inline std::string var_david9 = "66";
inline std::string var_leola2 = "Hidden";
inline std::string var_andrew1 = "90";
inline std::string var_johnny10 = "1";
inline std::string var_may5 = "2";
inline std::string var_robert10 = "0";
inline std::string var_elizabeth8 = "0";

#define MAX_SPRITES 8
inline Sprite sprites[8] = {
	{"plushtrapphases", -240, -180, 89, "3411e5d0c77773dcd7c3b13460f618d3.png", 2, 0},
	{"plushtrapjumpscare", -221, -166, 150, "e4cf287f0970b6adca0a1ca1e67e84d1.png", 4, 0},
	{"Intro", -55, -6, 123, "e731041a7603fb20bfbc0f30681cfbe5.png", 1, 0},
	{"Timer1", 203, -161, 138, "1eed73106763f67e5d42eca76ad91b85.png", 8, 0},
	{"Timer2", 223, -161, 148, "1eed73106763f67e5d42eca76ad91b85.png", 7, 0},
	{"TOO BAD.", 0, 0, 144, "bbefe594ad3f76a1d412e48ffd09872d.png", 3, 0},
	{"GREAT!", 2, 134, 145, "ca9f5f95c31f14c4527d169f6fac0010.png", 6, 0},
	{"Sprite1", -240, -180, 146, "b61b1077b0ea1931abee9dbbfa7903ff.png", 5, 0},
};
#define MAX_COSTUMES 147
inline Costume costumes[147] = {
	{"lights off", "51a431572696b9153d75f634a23c4a1b.png", 0, 0 , 0, 480, 360},
	{"plushtrapchair", "a18be64f8a7ca0b9ab67589a7c81d20b.png", 0, 0 , 0, 480, 360},
	{"plushtrapgone", "110e3a6815ca358c22f9554983669094.png", 0, 0 , 0, 480, 360},
	{"sitback1", "7b395e1b2734dc760f5a404d983f1741.png", 0, 0 , 0, 480, 360},
	{"sitback2", "4895db13ed285eaeb860c6ddc7fe3d43.png", 0, 0 , 0, 480, 360},
	{"sitback3", "f1ff57c62a3c8a400038540329faa030.png", 0, 0 , 0, 480, 360},
	{"sitback4", "3a4fe2bbca6d1e57d2677b2a5ec6fca0.png", 0, 0 , 0, 480, 360},
	{"sitback5", "ff7f17f538f10d44ce0ed4988a9f61a4.png", 0, 0 , 0, 480, 360},
	{"sitback6", "a18be64f8a7ca0b9ab67589a7c81d20b.png", 0, 0 , 0, 480, 360},
	{"hideleftfar1", "32718d555e81aff74650990f0c317d6d.png", 0, 0 , 0, 480, 360},
	{"hideleftfar2", "7af6c8a6f147939932117268f87589be.png", 0, 0 , 0, 480, 360},
	{"hideleftfar3", "3a43a6f7ff9739684cad89b5e88d8e63.png", 0, 0 , 0, 480, 360},
	{"hideleftfar4", "37c24f47fa3b3a6b830c7778d543c201.png", 0, 0 , 0, 480, 360},
	{"hideleftfar5", "3e191a149a849cfe0b53dfb8f107d0d6.png", 0, 0 , 0, 480, 360},
	{"hideleftfar6", "03ef6572c221c01464f26cf126a46807.png", 0, 0 , 0, 480, 360},
	{"hiderightfar1", "56b887a23f34615363c6f7f6946a6d0a.png", 0, 0 , 0, 480, 360},
	{"hiderightfar2", "c6c0809e7e79739f710235acca3c242c.png", 0, 0 , 0, 480, 360},
	{"hiderightfar3", "337460351999c821c9dd8a2e95010f82.png", 0, 0 , 0, 480, 360},
	{"hiderightfar4", "6102632b3ad0a3e0299e4539f7a71e3b.png", 0, 0 , 0, 480, 360},
	{"hiderightfar5", "0b107a85d3955de97b9e57d2b24f366c.png", 0, 0 , 0, 480, 360},
	{"hiderightfar6", "588198e8e9d153d6c62c043b7852c62a.png", 0, 0 , 0, 480, 360},
	{"hiderightclose1", "b3f0fc9129a3a1049b47c7cc4f20d226.png", 0, 0 , 0, 480, 360},
	{"hiderightclose2", "3916610f30c0efe2e599372d5ac8afd9.png", 0, 0 , 0, 480, 360},
	{"hiderightclose3", "014de4607dab783ca702caed3ebdb860.png", 0, 0 , 0, 480, 360},
	{"hiderightclose4", "1a33337918b933125b1d56d200372020.png", 0, 0 , 0, 480, 360},
	{"hiderightclose5", "de9a577e774928208f66d3f9ac9c6eb4.png", 0, 0 , 0, 480, 360},
	{"hiderightclose6", "0874453cdbd084993f1b39da531cf89f.png", 0, 0 , 0, 480, 360},
	{"hideleftclose1", "465704012bce2c2611e68ac1f02d4388.png", 0, 0 , 0, 480, 360},
	{"hideleftclose2", "d791c0797f61e1788da96bd404efd9ce.png", 0, 0 , 0, 480, 360},
	{"hideleftclose3", "8c43e1f4128ad772ab8912f18a8389b6.png", 0, 0 , 0, 480, 360},
	{"hideleftclose4", "113186954dd97326af833bc94506c9c9.png", 0, 0 , 0, 480, 360},
	{"hideleftclose5", "039e146a8cc3b1308ea51c01e2aa90b8.png", 0, 0 , 0, 480, 360},
	{"hideleftclose6", "62172a470d076070f8e7186ccf834aa9.png", 0, 0 , 0, 480, 360},
	{"middlefar1", "d455dcd5e72f7539a2356eb2facc8919.png", 0, 0 , 0, 480, 360},
	{"middlefar2", "ef98baaf95533cbb942e154ce9fb58db.png", 0, 0 , 0, 480, 360},
	{"middlefar3", "4cda2a25e08ba9708e67258edcaec398.png", 0, 0 , 0, 480, 360},
	{"middlefar4", "149231c2ffcc4644bec388b82a698c77.png", 0, 0 , 0, 480, 360},
	{"middlefar5", "a46690f7eb5e73ffb38d18bd5fb3b365.png", 0, 0 , 0, 480, 360},
	{"middlefar6", "07a322c83c40e628ab0dd2aadfe68cca.png", 0, 0 , 0, 480, 360},
	{"middleclose1", "3df4b410b5a74a657cf70827541aeb7f.png", 0, 0 , 0, 480, 360},
	{"middleclose2", "3fc3aa308ac65e6c2a1c59331a80417a.png", 0, 0 , 0, 480, 360},
	{"middleclose3", "09fd88e16a024ae04755bab6bcbcee07.png", 0, 0 , 0, 480, 360},
	{"middleclose4", "775183100f2f8755d72e4e4e6e96a8c8.png", 0, 0 , 0, 480, 360},
	{"middleclose5", "87a7785675b657e8803d038f290f8660.png", 0, 0 , 0, 480, 360},
	{"middleclose6", "4dd6fd7f19cbce305d8182bcd7f1fa2b.png", 0, 0 , 0, 480, 360},
	{"middleclose7", "33bcadd8143f72119d1a64293c4a9725.png", 0, 0 , 0, 480, 360},
	{"download", "7e9d24afe3d28a6de567aea667ec9253.png", 0, 0 , 0, 240, 180},
	{"0B169AE3-DE0E-49B5-8C73-7FCA4486F9EB", "7a9710d6f2e0d6f95beccb02f77b8992.png", 0, 0 , 0, 480, 360},
	{"0B169AE3-DE0E-49B5-8C73-7FCA4486F9EB2", "b763c417b8735c867074899c27ba02d7.png", 0, 0 , 0, 480, 360},
	{"0B169AE3-DE0E-49B5-8C73-7FCA4486F9EB3", "0db9a4ae210bda97a65c5793a003f82e.png", 0, 0 , 0, 480, 360},
	{"0B169AE3-DE0E-49B5-8C73-7FCA4486F9EB4", "3123de2ecc68a80f51dbd89c6853e897.png", 0, 0 , 0, 480, 360},
	{"0B169AE3-DE0E-49B5-8C73-7FCA4486F9EB5", "0bc6d5a8218e204193e7cd44983d7ac5.png", 0, 0 , 0, 480, 360},
	{"Output_5s9xvw2", "3d90d3b355d6e556441e762b39aa2fb8.png", 0, 0 , 0, 480, 360},
	{"Output_5s9xvw", "ccf21d757f655fe0e5e594bf2d2defd0.png", 0, 0 , 0, 480, 360},
	{"Output_5s9xvw3", "872a9bb2672d9db17ed49157b99d188f.png", 0, 0 , 0, 480, 360},
	{"Output_5s9xvw4", "4617602edd8432d9686da056e5bba89d.png", 0, 0 , 0, 480, 360},
	{"Output_5s9xvw6", "c0405020a73cbe409eac40e705c4ba58.png", 0, 0 , 0, 480, 360},
	{"Output_5s9xvw5", "40983cadaff4587252f4f686f93d94c1.png", 0, 0 , 0, 480, 360},
	{"Output_Kosjt0", "50504727b8c2b81118a52255a50c0d9f.png", 0, 0 , 0, 480, 360},
	{"Output_Kosjt03", "7e4ed60ca250dfb0180f4767f9377655.png", 0, 0 , 0, 480, 360},
	{"Output_Kosjt04", "9ceb04c5cefe2e8acee6fc1ec59b96a5.png", 0, 0 , 0, 480, 360},
	{"Output_Kosjt02", "d5a162b7fd8f4ba3c86f35612786596e.png", 0, 0 , 0, 480, 360},
	{"Output_Kosjt05", "425c0ff2ac9e18bf1c5d9a2bf7d4f727.png", 0, 0 , 0, 480, 360},
	{"Output_Kosjt06", "a6da8cf4ed270813a180b15d6fb1b701.png", 0, 0 , 0, 480, 360},
	{"Output_gKtOjE", "0799f01a52f875ee1003df92c5755436.png", 0, 0 , 0, 480, 360},
	{"Output_gKtOjE2", "51288782e9e4eddb728a33d27cd8e596.png", 0, 0 , 0, 480, 360},
	{"Output_gKtOjE3", "d5db1b50196a63c8fac7e8ca55b6d0df.png", 0, 0 , 0, 480, 360},
	{"Output_gKtOjE4", "0f339150fe82f6fc3fd383c38e38e25e.png", 0, 0 , 0, 480, 360},
	{"Output_gKtOjE5", "f4d448067f595022b74c65feabf47c52.png", 0, 0 , 0, 480, 360},
	{"Output_gKtOjE6", "9b49f5f11910e929ab878b17ab3798f6.png", 0, 0 , 0, 480, 360},
	{"Output_gKtOjE7", "bd8bef100fa7197d682ce20603a4fea0.png", 0, 0 , 0, 239, 181},
	{"Output_gcgFam", "a02d4aaa0499a3da0f4de009eabff057.png", 0, 0 , 0, 480, 360},
	{"Output_gcgFam3", "e5e25d52e16cc301ede33b883ae14200.png", 0, 0 , 0, 480, 360},
	{"Output_gcgFam2", "8c593eab5b84c5bdaa0fbd5c1983c92f.png", 0, 0 , 0, 480, 360},
	{"Output_gcgFam4", "90c83b6cbd0aaa50291d57e2b4cde432.png", 0, 0 , 0, 480, 360},
	{"Output_gcgFam5", "7fb7e2cbabddf7df9c4ddaa827b9d8a1.png", 0, 0 , 0, 480, 360},
	{"Output_gcgFam6", "b6a956302d64c9c64cdfc1e93751148e.png", 0, 0 , 0, 480, 360},
	{"Output_SVEvgY", "4412721111774d551e4f50e319480cdb.png", 0, 0 , 0, 480, 360},
	{"Output_SVEvgY2", "6f19e65ad616a2acfb2314d66167d77b.png", 0, 0 , 0, 480, 360},
	{"Output_SVEvgY3", "a4aa524798e525a88209346066f8f227.png", 0, 0 , 0, 480, 360},
	{"Output_SVEvgY4", "454c808dddd452c2d21e3dc31724bea5.png", 0, 0 , 0, 480, 360},
	{"Output_SVEvgY5", "d78f1c7ac13e7c8a7193a363bae8b1c2.png", 0, 0 , 0, 480, 360},
	{"Output_SVEvgY6", "1d98e2b8703aba834b334744ccc9eee5.png", 0, 0 , 0, 480, 360},
	{"download (1)", "2e51d65049c519187f02cec14a5f2a11.png", 0, 0 , 0, 241, 180},
	{"Output_J0bbDP", "69734df54dd0068c726ad197a258527c.png", 0, 0 , 0, 480, 360},
	{"Output_J0bbDP2", "9433d0d947f407a1b98efec5cd8129df.png", 0, 0 , 0, 480, 360},
	{"Output_J0bbDP3", "3d271a98799ad34c70f7353da8355466.png", 0, 0 , 0, 480, 360},
	{"Output_J0bbDP4", "075b9a026fa865489c20dab35172fe38.png", 0, 0 , 0, 480, 360},
	{"Output_J0bbDP5", "6a51061230137441801f3fd57c32c429.png", 0, 0 , 0, 480, 360},
	{"Output_J0bbDP6", "3411e5d0c77773dcd7c3b13460f618d3.png", 0, 0 , 0, 480, 360},
	{"Nightmare_bb_scare", "b3eb64f4b2ba086de0aa5f0e585a8463.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare2", "7f63efa8ae0621adebfa50802fe116ba.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare4", "d6396c450ffe76f9a4fec5ca801d656e.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare3", "4a9c2796520f6256ffbea891e55bd918.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare6", "776802e44565d897d2a82b8d83ec4583.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare5", "5401f84d9487b6c1fc908663f494fce8.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare8", "a7e5acc731827feb28ba3f61d1b57885.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare7", "074fdc660d6c14eaf78e022918d62b51.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare9", "08180d4068b4fcef01048dc58587d702.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare11", "6a16e9d18b80215b9ac14d99692e978f.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare13", "f2ce56f1661ec08bb011087f65af636f.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare10", "5fb3ab85314c35af9617479263091893.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare15", "632709fa83a3b97481ca4705b2876d26.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare12", "5b79ea993e64c1d81ed32ed0cae7a527.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare16", "00d52eaf0c94bd4019eb65b1fda7543a.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare17", "07a8d60cda95b183e41082c607e23bbe.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare14", "a7820916a47b1f4834019199bc6d8efa.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare18", "916229f337d5ee55adeb0a06d198a7b0.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare19", "e0f5ea1004a97f459f4e00e45e3e877e.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare20", "107895b71c2c19503098c680c65efb43.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare21", "0133b16da1c601eb9469d0750d1d35cf.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare23", "31d3e658aad8c8b1ae4cdf2e8ed92937.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare22", "9d40fde255f8bbe9d3e2f46012647954.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare25", "9654492c0a13dfded237092cfdd4688b.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare24", "c5f3940e772ab76c9f242da2539492a9.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare27", "0b7d46b4c8eec57a6d6a9abf803712a4.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare26", "498931119b1ac294dbe2a3cce4e30d70.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare29", "80a506f7334cc25282d376f5d76b5df5.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare30", "173188578e41486cc92596982d2a93ac.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare31", "5ab90ee9be28d9de05c50a620ee00f28.png", 1, 0 , 0, 461, 346},
	{"Nightmare_bb_scare28", "e4cf287f0970b6adca0a1ca1e67e84d1.png", 1, 0 , 0, 461, 346},
	{"1", "2ad594ddc492fe26773d09ec4305f26f.png", 2, 0 , 0, 240, 180},
	{"0", "e731041a7603fb20bfbc0f30681cfbe5.png", 2, 0 , 0, 295, 186},
	{"costume1", "c9bac7e5ea006fcc8034b91c5fbf4c7d.png", 3, 0 , 0, 240, 180},
	{"costume2", "2243bc4d2f51914f98e90295359205f2.png", 3, 0 , 0, 240, 180},
	{"costume3", "9c69a9e29680d52d941a593ccb688daf.png", 3, 0 , 0, 240, 180},
	{"costume4", "e85144ddd6adb1118dc641baecd38ea2.png", 3, 0 , 0, 240, 180},
	{"costume5", "669be587726b27917d63f72d59cf4854.png", 3, 0 , 0, 240, 180},
	{"costume6", "6aab74333c2cc20356a44f5dd2ee4982.png", 3, 0 , 0, 240, 180},
	{"costume7", "d10e524a3063f7b51cfd9127cfff415a.png", 3, 0 , 0, 240, 180},
	{"costume8", "1de153ecdda669fa570a954ced0fa2da.png", 3, 0 , 0, 240, 180},
	{"costume9", "970e0140f26c1cbedd54c4cfd976e82c.png", 3, 0 , 0, 240, 180},
	{"costume10", "1eed73106763f67e5d42eca76ad91b85.png", 3, 0 , 0, 240, 180},
	{"costume1", "c9bac7e5ea006fcc8034b91c5fbf4c7d.png", 4, 0 , 0, 240, 180},
	{"costume2", "2243bc4d2f51914f98e90295359205f2.png", 4, 0 , 0, 240, 180},
	{"costume3", "9c69a9e29680d52d941a593ccb688daf.png", 4, 0 , 0, 240, 180},
	{"costume4", "e85144ddd6adb1118dc641baecd38ea2.png", 4, 0 , 0, 240, 180},
	{"costume5", "669be587726b27917d63f72d59cf4854.png", 4, 0 , 0, 240, 180},
	{"costume6", "6aab74333c2cc20356a44f5dd2ee4982.png", 4, 0 , 0, 240, 180},
	{"costume7", "d10e524a3063f7b51cfd9127cfff415a.png", 4, 0 , 0, 240, 180},
	{"costume8", "1de153ecdda669fa570a954ced0fa2da.png", 4, 0 , 0, 240, 180},
	{"costume9", "970e0140f26c1cbedd54c4cfd976e82c.png", 4, 0 , 0, 240, 180},
	{"costume10", "1eed73106763f67e5d42eca76ad91b85.png", 4, 0 , 0, 240, 180},
	{"dead", "0aaf0ee1d6808bc11094b3fcde3286e8.png", 5, 0 , 0, 480, 360},
	{"timeout", "bbefe594ad3f76a1d412e48ffd09872d.png", 5, 0 , 0, 240, 180},
	{"0", "ca9f5f95c31f14c4527d169f6fac0010.png", 6, 0 , 0, 238, 46},
	{"costume1", "b61b1077b0ea1931abee9dbbfa7903ff.png", 7, 0 , 0, 480, 360},
};
#define MAX_STAGES 1
inline Stage stages[1] = {
	{"backdrop1", "f5e250886e3bafbbd9bc2398a5e321c5.png"},
};
inline void event_whenbroadcastreceivedblock_0gary5(Sprite &_sprite) {
	data_setvariableto(var_leola2, "Chair", _sprite);
	control_repeat_until(, _sprite);
	operator_equals(, _sprite);
	control_wait("l", _sprite);
	operator_divide(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	sound_setvolumeto(, _sprite);
	sound_playuntildone(, _sprite);
	data_setvariableto(var_leola2, "Middle Far", _sprite);
	data_setvariableto(var_johnny10, "0", _sprite);
	control_wait("l", _sprite);
	operator_divide(, _sprite);
	operator_random(, _sprite);
	control_wait("l", _sprite);
	operator_divide(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	data_setvariableto(var_may5, "l", _sprite);
	operator_random(, _sprite);
	sound_setvolumeto(, _sprite);
	operator_random(, _sprite);

	}
	operator_equals(, _sprite);
	sound_playuntildone(, _sprite);
	data_setvariableto(var_leola2, "Right Far", _sprite);

	}
	operator_equals(, _sprite);
	sound_playuntildone(, _sprite);
	data_setvariableto(var_leola2, "Left Far", _sprite);
	data_setvariableto(var_johnny10, "0", _sprite);
	control_wait("l", _sprite);
	operator_random(, _sprite);
	data_setvariableto(var_johnny10, "1", _sprite);
	data_setvariableto(var_leola2, "Hidden", _sprite);
	control_wait("l", _sprite);
	operator_divide(, _sprite);
	operator_random(, _sprite);
	control_wait("l", _sprite);
	operator_divide(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	data_setvariableto(var_may5, "l", _sprite);
	operator_random(, _sprite);
	sound_setvolumeto(, _sprite);
	operator_random(, _sprite);

	}
	operator_equals(, _sprite);
	sound_playuntildone(, _sprite);
	data_setvariableto(var_leola2, "Right Close", _sprite);

	}
	operator_equals(, _sprite);
	sound_playuntildone(, _sprite);
	data_setvariableto(var_leola2, "Left Close", _sprite);
	data_setvariableto(var_johnny10, "0", _sprite);
	control_wait("l", _sprite);
	operator_random(, _sprite);
	data_setvariableto(var_johnny10, "1", _sprite);
	data_setvariableto(var_leola2, "Hidden", _sprite);
	control_wait("l", _sprite);
	operator_divide(, _sprite);
	operator_random(, _sprite);
	control_wait("l", _sprite);
	operator_divide(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	sound_setvolumeto(, _sprite);
	operator_random(, _sprite);
	sound_playuntildone(, _sprite);
	data_setvariableto(var_leola2, "Middle Close", _sprite);
	data_setvariableto(var_johnny10, "0", _sprite);
	control_wait("l", _sprite);
	operator_random(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	control_stop(_sprite);
};
inline void event_broadcastblock_83jim3(Sprite &_sprite) {
	control_stop(_sprite);
	control_wait("l", _sprite);
	operator_divide(, _sprite);
	operator_random(, _sprite);
};
inline void event_whenflagclickedblock_88helen0(Sprite &_sprite) {
	looks_switchbackdropto("backdrop1", _sprite);
	sound_setvolumeto(, _sprite);
	data_setvariableto(var_andrew1, "90", _sprite);
};
inline void event_whenflagclickedblock_93hellen7(Sprite &_sprite) {
	data_setvariableto(var_willie3, "0", _sprite);
	motion_gotoxy(0, 0, _sprite);
	looks_seteffectto(, _sprite);
	looks_hide(_sprite);
};
inline void event_whenbroadcastreceivedblock_98sarah2(Sprite &_sprite) {
	looks_switchcostumeto("lights off", _sprite);
	looks_show(_sprite);
	control_repeat(, _sprite);
	looks_changeeffectby(, _sprite);
	control_repeat_until(, _sprite);
	operator_equals(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);

	}
	operator_equals(, _sprite);
	looks_switchcostumeto("download", _sprite);

	}
	operator_equals(, _sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);

	}
	operator_equals(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	data_setvariableto(var_johnny10, "1", _sprite);
	looks_switchcostumeto("Output_5s9xvw2", _sprite);
	control_repeat(, _sprite);
	looks_nextcostume(_sprite);
	control_wait_until(, _sprite);
	operator_equals(, _sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);

	}
	operator_equals(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	data_setvariableto(var_johnny10, "1", _sprite);
	looks_switchcostumeto("Output_Kosjt0", _sprite);
	control_repeat(, _sprite);
	looks_nextcostume(_sprite);
};
inline void event_broadcastblock_138august10(Sprite &_sprite) {
	control_stop(_sprite);
	looks_switchcostumeto("Output_Kosjt06", _sprite);

	}
	operator_equals(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	data_setvariableto(var_johnny10, "1", _sprite);
	looks_switchcostumeto("Output_gKtOjE", _sprite);
	control_repeat(, _sprite);
	looks_nextcostume(_sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);
	control_wait_until(, _sprite);
	operator_equals(, _sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);

	}
	operator_equals(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	data_setvariableto(var_johnny10, "1", _sprite);
	looks_switchcostumeto("Output_gcgFam", _sprite);
	control_repeat(, _sprite);
	looks_nextcostume(_sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);
	control_wait_until(, _sprite);
	operator_equals(, _sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);

	}
	operator_equals(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	data_setvariableto(var_johnny10, "1", _sprite);
	looks_switchcostumeto("Output_SVEvgY", _sprite);
	control_repeat(, _sprite);
	looks_nextcostume(_sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);
	control_wait_until(, _sprite);
	operator_equals(, _sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);

	}
	operator_equals(, _sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	data_setvariableto(var_johnny10, "1", _sprite);
	looks_switchcostumeto("Output_J0bbDP", _sprite);
	control_repeat(, _sprite);
	looks_nextcostume(_sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);
	control_wait_until(, _sprite);
	operator_equals(, _sprite);
	looks_switchcostumeto("plushtrapgone", _sprite);
	looks_switchcostumeto("lights off", _sprite);
};
inline void event_whenkeypressedblock_204diana7(Sprite &_sprite) {

	}
	operator_and(, _sprite);
	operator_gt(, _sprite);
	operator_and(, _sprite);
	operator_equals(, _sprite);
	operator_equals(, _sprite);
	sound_play(, _sprite);
	control_repeat_until(, _sprite);
	operator_not(, _sprite);
	sensing_keypressed(, _sprite);
	data_setvariableto(var_willie3, "1", _sprite);
	data_setvariableto(var_willie3, "0", _sprite);
	sound_play(, _sprite);
	data_setvariableto(var_johnny10, "0", _sprite);
};
inline void event_whenbroadcastreceivedblock_222curtis0(Sprite &_sprite) {
	looks_hide(_sprite);
};
inline void event_whenflagclickedblock_224roscoe0(Sprite &_sprite) {
	control_wait("8", _sprite);
	sound_play(, _sprite);
};
inline void event_whenflagclickedblock_228elizabeth7(Sprite &_sprite) {
	data_setvariableto(var_robert10, "0", _sprite);
	looks_switchcostumeto("0", _sprite);
	motion_gotoxy(0, 0, _sprite);
	looks_hide(_sprite);
};
inline void event_whenbroadcastreceivedblock_234david3(Sprite &_sprite) {
	looks_show(_sprite);
	data_setvariableto(var_robert10, "1", _sprite);
	looks_gotofrontback(_sprite);
	looks_switchcostumeto("Nightmare_bb_scare", _sprite);
	sound_play(, _sprite);
	control_repeat(, _sprite);
	looks_nextcostume(_sprite);
	looks_hide(_sprite);
};
inline void event_broadcastblock_245traci7(Sprite &_sprite) {
inline void event_whenflagclickedblock_246philip3(Sprite &_sprite) {
	data_setvariableto(var_david9, "0", _sprite);
	data_setvariableto(var_andrew1, "0", _sprite);
	motion_gotoxy(0, 0, _sprite);
	looks_show(_sprite);
	looks_cleargraphiceffects(_sprite);
	data_setvariableto(var_brian10, "1", _sprite);
	data_showvariable(_sprite);
	control_wait_until(, _sprite);
	sensing_keypressed(, _sprite);

	}
	operator_equals(, _sprite);
	data_setvariableto(var_david9, "90", _sprite);
	data_setvariableto(var_andrew1, "90", _sprite);

	}
	operator_equals(, _sprite);
	data_setvariableto(var_david9, "80", _sprite);
	data_setvariableto(var_andrew1, "80", _sprite);

	}
	operator_equals(, _sprite);
	data_setvariableto(var_david9, "70", _sprite);
	data_setvariableto(var_andrew1, "70", _sprite);

	}
	operator_equals(, _sprite);
	data_setvariableto(var_david9, "60", _sprite);
	data_setvariableto(var_andrew1, "60", _sprite);

	}
	operator_equals(, _sprite);
	data_setvariableto(var_david9, "50", _sprite);
	data_setvariableto(var_andrew1, "50", _sprite);
	data_hidevariable(_sprite);
	control_repeat(, _sprite);
	looks_changeeffectby(, _sprite);
	looks_hide(_sprite);
	control_wait("1", _sprite);
};
inline void event_broadcastblock_282carman3(Sprite &_sprite) {
inline void event_whenbroadcastreceivedblock_283timothy5(Sprite &_sprite) {
	sound_setvolumeto(, _sprite);
	gWhileLoop++;
};
inline void control_foreverblock_285marie9(Sprite &_sprite) {
	sound_playuntildone(, _sprite);
	sound_playuntildone(, _sprite);
};
inline void event_whenflagclickedblock_288carlos7(Sprite &_sprite) {
	looks_seteffectto(, _sprite);
	motion_gotoxy(203, 161, _sprite);
	looks_hide(_sprite);
};
inline void event_whenbroadcastreceivedblock_292lyda0(Sprite &_sprite) {
	looks_show(_sprite);
	control_repeat_until(, _sprite);
	operator_or(, _sprite);
	operator_equals(, _sprite);
	operator_equals(, _sprite);
	looks_gotofrontback(_sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	operator_length(, _sprite);
	looks_switchcostumeto(, _sprite);
	operator_add(, _sprite);
	operator_letter_of(, _sprite);
	looks_switchcostumeto("costume1", _sprite);
};
inline void event_whenbroadcastreceivedblock_308christopher6(Sprite &_sprite) {
	control_repeat_until(, _sprite);
	operator_or(, _sprite);
	operator_equals(, _sprite);
	operator_equals(, _sprite);
	control_wait("1", _sprite);
	data_changevariableby(, _sprite);
};
inline void event_whenbroadcastreceivedblock_315pamela7(Sprite &_sprite) {
	looks_hide(_sprite);
};
inline void event_whenflagclickedblock_317david3(Sprite &_sprite) {
	sound_setvolumeto(, _sprite);
	gWhileLoop++;
};
inline void control_foreverblock_319amy7(Sprite &_sprite) {
	sound_playuntildone(, _sprite);
	sound_playuntildone(, _sprite);
};
inline void event_whenbroadcastreceivedblock_322gail10(Sprite &_sprite) {
	sound_stopallsounds(_sprite);
};
inline void event_whenflagclickedblock_324claire3(Sprite &_sprite) {
	looks_seteffectto(, _sprite);
	motion_gotoxy(223, 161, _sprite);
	looks_hide(_sprite);
};
inline void event_whenbroadcastreceivedblock_328ellen8(Sprite &_sprite) {
	looks_show(_sprite);
	control_repeat_until(, _sprite);
	operator_or(, _sprite);
	operator_equals(, _sprite);
	operator_equals(, _sprite);
	looks_gotofrontback(_sprite);
	control_if_else(, _sprite);
	operator_equals(, _sprite);
	operator_length(, _sprite);
	looks_switchcostumeto(, _sprite);
	operator_add(, _sprite);
	operator_letter_of(, _sprite);
	looks_switchcostumeto(, _sprite);
	operator_add(, _sprite);
	operator_letter_of(, _sprite);
};
inline void event_whenbroadcastreceivedblock_346gregory0(Sprite &_sprite) {
	looks_hide(_sprite);
};
inline void event_whenflagclickedblock_348joanne0(Sprite &_sprite) {
	motion_gotoxy(0, 0, _sprite);
	looks_hide(_sprite);
};
inline void event_whenbroadcastreceivedblock_351carrie1(Sprite &_sprite) {
	looks_switchcostumeto("dead", _sprite);
	looks_show(_sprite);
	control_wait("3", _sprite);
	control_stop(_sprite);
};
inline void event_whenbroadcastreceivedblock_357edward6(Sprite &_sprite) {
	control_wait_until(, _sprite);
	operator_equals(, _sprite);
	looks_gotofrontback(_sprite);
	looks_switchcostumeto("timeout", _sprite);
	looks_show(_sprite);
	looks_seteffectto(, _sprite);
	control_repeat(, _sprite);
	looks_changeeffectby(, _sprite);
	control_stop(_sprite);
};
inline void event_whenflagclickedblock_368steven3(Sprite &_sprite) {
	data_setvariableto(var_elizabeth8, "0", _sprite);
	motion_gotoxy(0, 0, _sprite);
	looks_hide(_sprite);
};
inline void event_whenbroadcastreceivedblock_372marion10(Sprite &_sprite) {
	data_setvariableto(var_elizabeth8, "1", _sprite);
	looks_gotofrontback(_sprite);
	looks_show(_sprite);
	control_stop(_sprite);
};
inline void event_whenflagclickedblock_377tina9(Sprite &_sprite) {
	motion_gotoxy(0, 0, _sprite);
	looks_hide(_sprite);
};
inline void event_whenbroadcastreceivedblock_380marcia8(Sprite &_sprite) {
	sound_stopallsounds(_sprite);
	looks_show(_sprite);
	looks_gotofrontback(_sprite);
	looks_cleargraphiceffects(_sprite);
	control_wait("0.3", _sprite);
	control_repeat(, _sprite);
	looks_gotofrontback(_sprite);
	looks_changeeffectby(, _sprite);
	looks_hide(_sprite);
};

#define MAX_WHILES 2
inline void(*_whileLoops[2])(Sprite &_sprite) {
	&control_foreverblock_285marie9,
	&control_foreverblock_319amy7,
};

inline void(*_spriteClicked[0])(Sprite &_sprite) {
};

inline void(*_greenFlagClicked[11])(Sprite &_sprite) {
	&event_whenflagclickedblock_88helen0,
	&event_whenflagclickedblock_93hellen7,
	&event_whenflagclickedblock_224roscoe0,
	&event_whenflagclickedblock_228elizabeth7,
	&event_whenflagclickedblock_246philip3,
	&event_whenflagclickedblock_288carlos7,
	&event_whenflagclickedblock_317david3,
	&event_whenflagclickedblock_324claire3,
	&event_whenflagclickedblock_348joanne0,
	&event_whenflagclickedblock_368steven3,
	&event_whenflagclickedblock_377tina9,
};
