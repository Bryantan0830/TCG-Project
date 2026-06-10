// CGLabProject.hpp
#ifndef YP_CGLAB01_HPP
#define YP_CGLAB01_HPP

#include "CGLabmain.hpp"
#include <string>
#include <vector>
#include <sstream>

namespace CGLabProject
{

    class Umbreon
    {
    public:
        // Animation variables - move these from global to class
        bool isAnimating = false;
        float currentBackBodyRotation = 0.0f;
        float targetBackBodyRotation = 0.0f;
        float currentTranslateX = 0.0f;
        float targetTranslateX = 0.0f;
        float currentTranslateZ = 0.0f;
        float targetTranslateZ = 0.0f;
        float currentLegTranslateX = 0.0f;
        float targetLegTranslateX = 0.0f;
        float rotationSpeed = 2.0f;
        float translationSpeed = 0.02f;
        float holdTimer = 0.0f;
        float holdDuration = 120.0f;
        bool isReturning = false;

        // Faint animation variables (keep these)
        bool isFainted = false;
        float faintRotation = 0.0f;
        float faintAnimationTimer = 0.0f;
        bool faintAnimationComplete = false;

        void draw(const float vertices[][3], int numVertices, const int faces[][3], int numFaces);
        void drawmodel();
        void toggleStanding();
        void updateAnimation();
        void updateFaintAnimation();

        void startFaintAnimation()
        {
            isFainted = true;
            faintAnimationTimer = 0.0f;
            faintAnimationComplete = false;
        }
    };

    // Magnemite starts from here
    class Body
    {
    public:
        void draw();
    };

    class drawBentCylinder
    {
    public:
        float bendRadius, startAngle, endAngle;
        int segments;
        float cylRadius, segmentHeight;

        drawBentCylinder(float bendRadius, float startAngle, float endAngle,
                         int segments, float cylRadius, float segmentHeight)
            : bendRadius(bendRadius), startAngle(startAngle), endAngle(endAngle),
              segments(segments), cylRadius(cylRadius), segmentHeight(segmentHeight) {}

        // Default constructor with default values
        drawBentCylinder()
            : bendRadius(0.25f), startAngle(0.0f), endAngle(M_PI),
              segments(100), cylRadius(0.05f), segmentHeight(0.1f) {}

        void draw() const;

    private:
        void drawCube(float size, float r, float g, float b) const;
        void drawCylinderSegment(GLUquadric *quad, float radius, float height) const;
    };

    class Screws
    {
    public:
        void draw() const;
    };

    class MyPoints
    {
    public:
        void draw();
    };

    class Magnemite
    {
    public:
        Magnemite() {}
        void draw();                  // Main switching function
        void drawMagnemite();         // Draws multiple Magnemites
        void drawMagnemiteDetailed(); // Add this new function declaration
        void drawMagneton();          // Draws Magneton

        float rotatingAngle = 0.0f;
        bool isMagneton = false;

        // Add faint animation variables
        bool isFainted = false;
        float faintRotation = 0.0f;
        float faintAnimationTimer = 0.0f;
        bool faintAnimationComplete = false;

        void startFaintAnimation()
        {

            isFainted = true;
            faintAnimationTimer = 0.0f;
            faintAnimationComplete = false;
        }
        void updateFaintAnimation();

        void evolveToMagneton();
        void devolveToMagnemite();

    private:
        Body body;
        Screws screws;
        drawBentCylinder drawbentcylinder;
        MyPoints mypoints;
    };
    // END

    // Battle_Platform and Effect starts from here
    class Battle_Platform
    {
    public:
        void drawPlat();
    };

    // Class representing a Pokemon character
    class Pokemon_1
    {
    public:
        float posX, posY, posZ; // Position of the Pokemon
        bool isAttacking;       // Whether the Pokemon is currently attacking

        Pokemon_1() : posX(0), posY(0), posZ(0), isAttacking(false) {}

        void drawPokemon(Magnemite &magnemite);      // Modified to accept Magnemite reference
        void triggerAttack() { isAttacking = true; } // Trigger the attack animation
        void update();                               // Update the Pokemon state
    };

    class Pokemon_2
    {
    public:
        float posX, posY, posZ; // Position of the Pokemon
        bool isAttacking;       // Whether the Pokemon is currently attacking

        Pokemon_2() : posX(0), posY(0), posZ(0), isAttacking(false) {}

        void drawPokemon(Umbreon &umbreon);          // Render the Pokemon model
        void triggerAttack() { isAttacking = true; } // Trigger the attack animation
        void update();                               // Update the Pokemon state
    };

    // Skill 1: ThunderShock skill
    class Skill_1
    {
    public:
        bool isActive;   // Whether the skill is active
        float duration;  // Skill duration in seconds
        float startTime; // Time when the skill started

        Skill_1() : isActive(false), duration(0.5f), startTime(0) {}

        void drawThunderShock();                     // Draw the ThunderShock skill effect
        void activate();                             // Activate the skill
        void update();                               // Update the skill state
        bool shouldDraw() const { return isActive; } // Whether to draw the skill effect
    };

    // Skill 2: Feint Attack skill
    class Skill_2
    {
    public:
        bool isActive;   // Whether the skill is active
        float duration;  // Skill duration in seconds
        float startTime; // Time when the skill started
        Skill_2() : isActive(false), duration(0.5f), startTime(0) {}

        void drawFeintAttack();                                                                  // Draw the Feint Attack skill effect
        void update();                                                                           // Update the skill state
        void activate();                                                                         // Activate the skill
        bool shouldDraw() { return isActive && effectDuration > 0.0f && effectDuration < 1.0f; } // Condition for drawing

    private:
        float attackTimer = 0.0f;     // Timer for attack animation
        float lastTime = 0.0f;        // Last update time
        float explosionRadius = 0.0f; // Radius of explosion effect
        float effectDuration = 0.0f;  // Duration progress of effect
    };

    // Skill 3: Thunderbolt skill
    class Skill_3
    {
    public:
        bool isActive;   // Whether the skill is active
        float duration;  // Skill duration in seconds
        float startTime; // Time when the skill started

        Skill_3() : isActive(false), duration(0.7f), startTime(0) {}

        void drawThunderbolt();                                                                                                         // Draw the Thunderbolt skill effect
        void drawBolt(float sx, float sy, float sz, float ex, float ey, float ez, float width, float alpha, bool isMain, int segments); // Helper to draw individual bolts
        void activate();                                                                                                                // Activate the skill
        void update();                                                                                                                  // Update the skill state
        bool shouldDraw() const { return isActive; }                                                                                    // Whether to draw the skill effect

    private:
        float boltWidth = 3.0f; // Width of the lightning bolt
    };

    // Skill 4: Assurance skill
    class Skill_4
    {
    public:
        bool isActive;   // Whether the skill is active
        float duration;  // Skill duration in seconds
        float startTime; // Time when the skill started

        Skill_4() : isActive(false), duration(0.5f), startTime(0) {}

        void drawAssurance();                        // Draw the Assurance skill effect
        void activate();                             // Activate the skill
        void update();                               // Update the skill state
        bool shouldDraw() const { return isActive; } // Whether to draw the skill effect
    };
    // END

    //------------------------------------
    // the main program will call methods from this class
    class MyVirtualWorld
    {
    private:
        float playerHP; // Current HP for player's Pokemon (0-100)
        float enemyHP;  // Current HP for enemy's Pokemon (0-100)

        bool isPlayerTurn;
        int selectedSkill;
        std::vector<std::string> skills;
        std::vector<std::string> player1Skills;
        std::vector<std::string> player2Skills;
        std::string playerName;
        std::string statusMessage;
        int currentSelection;
        int selectedSkillP1;
        int selectedSkillP2;
        float turnTimer;
        void drawSkillMenu(float x, float y, const std::vector<std::string> &skills, const std::string &title, int selected, const std::string &skillType);
        void drawPokemonUI(float x, float y, const std::string &name, int level, float currentHP, float maxHP, bool isPlayer, char gender = 'M');
        void drawStatusMessage(const std::string &message);
        void executeSkill(int skillIndex, bool isPlayer1);

        // Add these flags to prevent repeated faint animation triggering
        bool magnemiteFaintTriggered = false;
        bool umbreonFaintTriggered = false;

        enum TurnState
        {
            PLAYER1_SELECTING,
            PLAYER1_EXECUTING,
            PLAYER2_SELECTING,
            PLAYER2_EXECUTING,
            BATTLE_END
        };

        TurnState currentTurnState;

    public:
        long int timeold, timenew, elapseTime;

        Magnemite magnemite;
        Body body;
        drawBentCylinder drawbentcylinder;

        Battle_Platform battle_plat; // Battle platform instance
        Pokemon_1 pokemon_1;         // First Pokemon instance
        Pokemon_2 pokemon_2;         // Second Pokemon instance
        Skill_1 skill_1;             // ThunderShock skill instance
        Skill_2 skill_2;             // Feint Attack skill instance
        Skill_3 skill_3;             // Thunderbolt skill instance
        Skill_4 skill_4;             // Assurance skill instance

        MyVirtualWorld()
            : drawbentcylinder(0.25f, 0.0f, M_PI, 100, 0.05f, 0.1f) {}
        MyPoints mypoints;
        Screws screws;

        Umbreon umbreon;

        void handleKeyInput(int key);

        /// Pokemon.hpp umbreon.hpp draw() later add in cpp
        void draw();

        void tickTime()
        {
            // Umbreon
            umbreon.updateAnimation(); // This should already be there

            umbreon.updateFaintAnimation(); // Add this line

            // Magnemite
            timenew = glutGet(GLUT_ELAPSED_TIME);
            elapseTime = timenew - timeold;
            timeold = timenew;

            magnemite.updateFaintAnimation(); // Add this line
            // Battle_Field and effect
            switch (currentTurnState)
            {
            case PLAYER1_SELECTING:
            case PLAYER2_SELECTING:
                // Handle selection states
                break;
            case PLAYER1_EXECUTING:
            case PLAYER2_EXECUTING:
                // Handle execution states
                turnTimer -= 0.016f; // Assuming 60fps
                if (turnTimer <= 0)
                {
                    // CHECK FOR BATTLE END CONDITIONS HERE!
                    if (playerHP <= 0 || enemyHP <= 0)
                    {
                        currentTurnState = BATTLE_END;
                        // Start faint animations ONLY ONCE
                        if (playerHP <= 0 && !magnemiteFaintTriggered)
                        {
                            statusMessage = "Umbreon wins!";
                            magnemite.startFaintAnimation();
                            magnemiteFaintTriggered = true; // Prevent repeated triggering
                        }
                        else if (enemyHP <= 0 && !umbreonFaintTriggered)
                        {
                            statusMessage = "Magnemite(Magneton) wins!";
                            umbreon.startFaintAnimation();
                            umbreonFaintTriggered = true; // Prevent repeated triggering
                        }
                    }
                    // Only continue turn progression if battle hasn't ended
                    else if (currentTurnState == PLAYER1_EXECUTING)
                    {
                        currentTurnState = PLAYER2_SELECTING;
                        statusMessage = "Umbreon's Turn!";
                    }
                    else
                    {
                        currentTurnState = PLAYER1_SELECTING;
                        statusMessage = "Magnemite(Magneton)'s Turn!";
                    }
                }
                break;
            case BATTLE_END:
                // Handle battle end - display win message
                if (playerHP <= 0)
                {
                    statusMessage = "Umbreon wins!";
                }
                else if (enemyHP <= 0)
                {
                    statusMessage = "Magnemite(Magneton) wins!";
                }
                break;
            }

            // Update all animations
            pokemon_1.update();
            pokemon_2.update();
            skill_1.update();
            skill_2.update();
            skill_3.update();
            skill_4.update();

            // Umbreon
        }

        void init()
        {
            // magnemite
            glEnable(GL_LIGHTING);

            timeold = glutGet(GLUT_ELAPSED_TIME);

            // battle_field
            playerHP = 100.0f;
            enemyHP = 100.0f;
            isPlayerTurn = true;
            selectedSkill = 0;
            currentSelection = 0;
            selectedSkillP1 = 0;
            selectedSkillP2 = 0;
            turnTimer = 0.0f;
            currentTurnState = PLAYER1_SELECTING;
            statusMessage = "Player 1's Turn!";
            playerName = "Magnemite(Magneton)";

            // Reset faint flags
            magnemiteFaintTriggered = false;
            umbreonFaintTriggered = false;

            player1Skills.clear();
            player2Skills.clear();
            player1Skills.push_back("Thunder Shock");
            player1Skills.push_back("Thunderbolt");
            player2Skills.push_back("Feint Attack");
            player2Skills.push_back("Assurance");

            glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        }
    };

}; // end of namespace CGLab01

#endif
