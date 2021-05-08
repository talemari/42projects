<?php 
    class Jaime {
        public function sleepWith($partner) {
            if (get_class($partner) == "Tyrion")
                print("Not even if I'm drunk !\n");
            else if (get_class($partner) == "Sansa")
                print("Let's do this.\n");
            else if (get_class($partner) == "Cersei")
                print("With pleasure, but only in a tower in Winterfell, then.\n");
        }
    }
?>