<?php 
    class Tyrion {
        public function sleepWith($partner) {
            if (get_class($partner) == "Jaime")
                print("Not even if I'm drunk !\n");
            else if (get_class($partner) == "Sansa")
                print("Let's do this.\n");
            else if (get_class($partner) == "Cersei")
                print("Not even if I'm drunk !\n");
        }
    }
?>