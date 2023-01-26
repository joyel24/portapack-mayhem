#include "ui_about_simple.hpp"

namespace ui
{
    AboutView::AboutView(NavigationView &nav)
    {
        add_children({&console, &button_ok});

        button_ok.on_select = [&nav](Button &)
        {
            nav.pop();
        };

        console.writeln("\x1B\x07List of contributors:\x1B\x10");
        console.writeln("");
    }

    void AboutView::update()
    {
        if (++timer > 200)
        {
            timer = 0;
            int x  = 5;

            switch (++frame)
            {
            case 1:
                // TODO: Generate this automatically from github
                // https://github.com/eried/portapack-mayhem/graphs/contributors?to=2022-01-01&from=2020-04-12&type=c
                console.writeln("\x1B\x06Mayhem:\x1B\x10"); if (timer < (x * timer) ){break;}
                console.writeln("eried,euquiq,gregoryfenton"); if (timer < (2 * x * timer) ){break;}
                console.writeln("johnelder,jwetzell,nnemanjan00"); if (timer < (3 * x * timer) ){break;}
                console.writeln("N0vaPixel,klockee,GullCode"); if (timer < (4 * x * timer) ){break;}
                console.writeln("jamesshao8,ITAxReal,rascafr"); if (timer < (5 * x * timer) ){break;}
                console.writeln("mcules,dqs105,strijar"); if (timer < (6 * x * timer) ){break;}
                console.writeln("zhang00963,RedFox-Fr,aldude999"); if (timer < (7 * x * timer) ){break;}
                console.writeln("East2West,fossum,ArjanOnwezen"); if (timer < (8 * x * timer) ){break;}
                //To do : put everywhere with interrupt instead of sleep
                console.writeln("vXxOinvizioNxX,teixeluis");chThdSleepMilliseconds(800);
                console.writeln("Brumi-2021,texasyojimbo");chThdSleepMilliseconds(800);
                console.writeln("heurist1,intoxsick,ckuethe");chThdSleepMilliseconds(800);
                console.writeln("notpike,jLynx,zigad,andrej-mk");chThdSleepMilliseconds(800);
                console.writeln("MichalLeonBorsuk,jimilinuxguy");chThdSleepMilliseconds(800);
                console.writeln("joyel24,BehleZebub,arneluehrs");chThdSleepMilliseconds(800);
                console.writeln("formtapez,F33RNI,rusty-labs");chThdSleepMilliseconds(800);
                console.writeln("gullradriel,igolyudov");chThdSleepMilliseconds(800);
                console.writeln("taskinen,MattLodge,TQMatvey");chThdSleepMilliseconds(800);
                console.writeln("RobertoD91,N0vaPixel,KimIV");chThdSleepMilliseconds(800);
                console.writeln("");
                break;

            case 2:
                // https://github.com/eried/portapack-mayhem/graphs/contributors?to=2020-04-12&from=2015-07-31&type=c
                console.writeln("\x1B\x06Havoc:\x1B\x10");
                console.writeln("furrtek,mrmookie,NotPike");
                console.writeln("mjwaxios,ImDroided,Giorgiofox");
                console.writeln("F4GEV,z4ziggy,xmycroftx");
                console.writeln("troussos,silascutler,RndmNmbr");
                console.writeln("nickbouwhuis,msoose,leres");
                console.writeln("joakar,dhoetger,clem-42");
                console.writeln("brianlechthaler,ZeroChaos-");
                console.writeln("Maescool,RndmNmbr,OpCode1300");
                console.writeln("");
                break;

            case 3:
                // https://github.com/eried/portapack-mayhem/graphs/contributors?from=2014-07-05&to=2015-07-31&type=c
                console.writeln("\x1B\x06PortaPack:\x1B\x10");
                console.writeln("jboone,argilo");
                console.writeln("");
                break;

            case 4:
                // https://github.com/mossmann/hackrf/graphs/contributors
                console.writeln("\x1B\x06HackRF:\x1B\x10");
                console.writeln("mossmann,dominicgs,bvernoux");
                console.writeln("bgamari,schneider42,miek");
                console.writeln("willcode,hessu,Sec42");
                console.writeln("yhetti,ckuethe,smunaut");
                console.writeln("wishi,mrbubble62,scateu...");
                console.writeln("");
                frame = 0; // Loop
                break;
            }
        }
    }

    void AboutView::focus()
    {
        button_ok.focus();
    }

} /* namespace ui */
